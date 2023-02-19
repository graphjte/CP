#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
#define ii pair<int, int>
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e15+7;

int n, R = 0;
map<char, ii > M;

ii gg(int a, int b) {
    if (a==0) {
        return {0,1};
    }
    ii tmp = gg(b%a,a);
    return {tmp.se - (b/a)*tmp.fi, tmp.fi};
}

void DFS(ii u, vector< vector<char> > &a, vector< vector<int> > &d) {
    ii v;
    v.first = u.first + M[a[u.first][u.second]].first;
    v.second = u.second + M[a[u.first][u.second]].second;
    if (d[v.first][v.second]==-1) {
        d[v.first][v.second] = d[u.first][u.second] + 1;
        R = max(R, d[v.first][v.second]);
        DFS(v, a, d);
    }
} 

signed main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    M['^'] = {-1, 0};
    M['v'] = {1, 0};
    M['<'] = {0, -1};
    M['>'] = {0, 1}; 

    int T;
    cin >> T;
    while (T--){
        R= 0;
        cin >> n;
        vector< vector<char> > a(n+2, vector<char>(n+2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        vector< vector<int> > d(n+3, vector<int>(n+3, -1));
        vector< vector<int> > e(n+3, vector<int>(n+3, -1));
        d[0][0] = 0;
        DFS({0,0}, a, d);

        int m;
        cin >> m;
        FOR(i,1,m) {
            int u, v;
            cin >> u >> v;
            e[u][v] = i-1;
        }
        int bad = false, res = MOD;
        FOR(i,0,n-1){
            FOR(j,0,n-1) {
                int rem_1 = d[i][j];
                int rem_2 = e[i][j];
                if (d[i][j]==-1 || e[i][j]==-1) continue;
               
                int x = R, y = m;
                FOR(k,0,1000){
                    if (((k*x + rem_1) % y) == rem_2){
                        res = min(res, k*x + rem_1);
                        // cout << rem_1 << " " << rem_2 << endl;
                    }
                } 
            }
        }
        if (res==MOD) {
            cout << "never\n";
        }
        else cout << res << "\n";
    }
    return 0;
}