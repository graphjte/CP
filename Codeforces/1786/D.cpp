#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=(int)b; ++i)
#define FORD(i,b,a) for (int i=b; i>=(int)a; --i)
using namespace std;

const int MAXN = 2e5+6;
const int MOD = 1e9+7;

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int sum = 0;
        vector<string> ss;
        map<string, vector<int> > M;   
        FOR(i,1,n) {
            string s;
            cin >> s;
            set<char> S;
            sort(s.begin(), s.end());
            ss.push_back(s);
            if (s != "inw") M[s].push_back(i-1);
        }
        ///www, iii, nnn
        vector<tuple<int, char, int, char> > res;
        bool quaylairoi = false;
        quaylai:
        while (M["www"].size()) {
            if (M["iin"].size() && M["inn"].size()) {
                int x = M["www"].back();
                M["www"].pop_back();
                int y = M["iin"].back();
                M["iin"].pop_back();
                int z = M["inn"].back();
                M["inn"].pop_back();
                //2
                res.push_back({x,'w',y,'i'});
                res.push_back({x, 'w', z, 'n'});
            }
            else break;
        }
        while (M["iii"].size()) {
            if (M["nnw"].size() && M["nww"].size()) {
                int x = M["iii"].back();
                M["iii"].pop_back();
                int y = M["nnw"].back();
                M["nnw"].pop_back();
                int z = M["nww"].back();
                M["nww"].pop_back();
                //2
                res.push_back({x,'i',y,'n'});
                res.push_back({x, 'i', z, 'w'});
            }
            else break;
        }
        while (M["nnn"].size()) {
            if (M["iiw"].size() && M["iww"].size()) {
                int x = M["nnn"].back();
                M["nnn"].pop_back();
                int y = M["iiw"].back();
                M["iiw"].pop_back();
                int z = M["iww"].back();
                M["iww"].pop_back();
                //2
                res.push_back({x,'n',y,'i'});
                res.push_back({x, 'n', z, 'w'});

            }
            else break;
        }
        //www, iii, nnn
        while (M["nnn"].size()) {
            if (M["iii"].size() && M["www"].size()) {
                int x = M["nnn"].back();
                M["nnn"].pop_back();
                int y = M["iii"].back();
                M["iii"].pop_back();
                int z = M["www"].back();
                M["www"].pop_back();
                //3
                res.push_back({x,'n',y,'i'});
                res.push_back({x, 'n', z, 'w'});
                res.push_back({y,'i',z,'w'});
            }
            else break;
        }
        while (M["nnn"].size()) {
            if (M["iii"].size()) {
                int x = M["nnn"].back();
                M["nnn"].pop_back();
                int y = M["iii"].back();
                M["iii"].pop_back();
                //3
                res.push_back({x,'n',y,'i'});
                ss[x] = "inn";
                ss[y] = "iin";
                M[ss[x]].push_back(x);
                M[ss[y]].push_back(y);
            }
            else break;
        }
        while (M["www"].size()) {
            if (M["iii"].size()) {
                int x = M["www"].back();
                M["www"].pop_back();
                int y = M["iii"].back();
                M["iii"].pop_back();
                //3
                res.push_back({x,'w',y,'i'});
                ss[x] = "iww";
                ss[y] = "iiw";
                M[ss[x]].push_back(x);
                M[ss[y]].push_back(y);
            }
            else break;
        }
        while (M["www"].size()) {
            if (M["nnn"].size()) {
                int x = M["www"].back();
                M["www"].pop_back();
                int y = M["nnn"].back();
                M["nnn"].pop_back();
                //3
                res.push_back({x,'w',y,'n'});
                ss[x] = "nww";
                ss[y] = "nnw";
                M[ss[x]].push_back(x);
                M[ss[y]].push_back(y);
            }
            else break;
        }
        while (M["iii"].size()) {
            for(auto &tmp: M) {
                if (tmp.first[0]!='i' && tmp.second.size()) {
                    int x = M["iii"].back();
                    M["iii"].pop_back();
                    int y = tmp.second.back();
                    tmp.second.pop_back();
                    ss[x][2] = ss[y][1];
                    M[ss[x]].push_back(x);
                    res.push_back({x, 'i', y, ss[y][1]});
                    break;
                }
            }
        }
        while (M["www"].size()) {
            for(auto &tmp: M) {
                if (tmp.first[2]!='w' && tmp.second.size()) {
                    int x = M["www"].back();
                    M["www"].pop_back();
                    int y = tmp.second.back();
                    tmp.second.pop_back();
                    ss[x][0] = ss[y][1];
                    M[ss[x]].push_back(x);
                    res.push_back({x, 'w', y, ss[y][1]});
                    break;
                }
            }
        }
        while (M["nnn"].size()) {
            for(auto &tmp: M) {
                if (tmp.first[0]!='n' && tmp.first[2]!=n) {
                    int x = M["nnn"].back();
                    M["nnn"].pop_back();
                    int y = tmp.second.back();
                    tmp.second.pop_back();
                    int pos = 2;
                    if (tmp.first[1] == 'i') pos = 0;
                    ss[x][pos] = ss[y][1];
                    M[ss[x]].push_back(x);
                    res.push_back({x, 'i', y, ss[y][1]});
                    break;
                }
            }
        }
        if(!quaylairoi) {
            quaylairoi = true;
            goto quaylai;
        }
        vector<pair<string, string> > p = {{"inn", "iww"}, {"iin", "nww"}, {"iiw", "nnw"}} ;
        for(auto [s, t]: p) {
            while (M[s].size() && M[t].size()) {
                int x = M[s].back();
                M[s].pop_back();
                int y = M[t].back();
                M[t].pop_back();
                res.push_back({x, s[1], y, t[1]});
            }
        }
        vector<vector<int> > tmp2;
        for(auto tmp: M) {
            if (tmp.second.size()) {
                tmp2.push_back(tmp.second);
            }
        }
        if (!tmp2.empty()) 
        for(int i = 0; i < tmp2[0].size(); i++) {
            int x = tmp2[0][i];
            int y = tmp2[1][i];
            int z = tmp2[2][i];
            res.push_back({x, ss[x][1], y, ss[y][1]});
            res.push_back({y, ss[x][1], z, ss[z][1]});
        }
        cout << res.size() << "\n";
        for(auto [x, y, z, t]: res) {
            cout << x+1 << " " << y << " " << z+1 << " " << t << "\n";
        } 
    }
    return 0;
}