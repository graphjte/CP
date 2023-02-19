#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 2e5+6;
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
        int sum = 0, n, m;
        cin >> n >> m;
        vector< vector<int> > a(n+1, vector<int>(m+1));
        vector<ii> L, R;
        vector<int> cnt(n+3);
        FOR(i,1,n) {
            FOR(j,1,m) {
                cin >> a[i][j];
                cnt[i]+= (a[i][j]==1);
            }
            sum+= cnt[i];
        }
        if (sum %n !=0) {
            cout << -1 << "\n";
            continue;
        }
        sum/=n; 
        FOR(i,1,n) {
                if (cnt[i] < sum) {
                    L.push_back({i, sum - cnt[i]});
                }
                else if (cnt[i] > sum) R.push_back({i, cnt[i] - sum});
        }
        vector<tuple<int, int, int> > res;
        for(int i=0; i < L.size(); i++) {
            int row = L[i].first, num = L[i].second;
            while (num > 0) {
                ii tmp = R.back(); R.pop_back();
                for(int j = 1; j<=m; j++)
                {
                    if (num == 0) break;
                    if (tmp.second == 0) break;
                    if (a[tmp.first][j] == 1 && a[row][j] == 0) {
                        res.push_back({row, tmp.fi, j});
                        // cout << num << " " << tmp.second << "\n";
                        a[row][j]  = 1;
                        a[tmp.first][j] = 0;
                        num--;
                        tmp.second--;
                    }
                }
                if (tmp.se > 0) {
                    R.push_back(tmp);
                }
            }
        }
        cout << res.size() << "\n";
        for(auto &tmp: res) {
            cout << get<1>(tmp) << " ";
            cout << get<0>(tmp) << " ";
            cout << get<2>(tmp) << "\n";
        }
    }
    return 0;
}