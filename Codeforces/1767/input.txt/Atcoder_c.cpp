//prob: https://atcoder.jp/contests/arc074/tasks/arc074_c
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 3e2+6;
const int MOD = 1e9+7;

vector<ii> constraints[MAX];
int dp[MAX][MAX][MAX];

bool Check(int r, int g, int b, int cur_pos) {
    for(auto &tmp: constraints[cur_pos]) {
        int l = tmp.fi, x = tmp.se, cnt = 0;
        if (r >= l) cnt++;
        if (g >= l) cnt++;
        if (b >= l) cnt++;
        if (cnt != x) return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }

    int n, m; 
    cin >> n >> m;
    FOR(i,1,m) {
        int l, r, x;
        cin >> l >> r >> x;
        constraints[r].push_back({l,x});
    } 
    if (Check(1,0,0,1)) dp[1][0][0] = dp[0][1][0] = dp[0][0][1] = 1;
    int res = 0;
    FOR(r,0,n) {
        FOR(g,0,n) {
            FOR(b,0,n) {
                int i = max({r,g,b});
                if (Check(i+1,g,b, i+1))  {
                    dp[i+1][g][b]+= dp[r][g][b];
                    dp[i+1][g][b]%= MOD;
                }
                if (Check(r,i+1,b, i+1))  {
                    dp[r][i+1][b]+= dp[r][g][b];
                    dp[r][i+1][b]%= MOD;
                }
                if (Check(r,g,i+1, i+1))  {
                    dp[r][g][i+1]+= dp[r][g][b];
                    dp[r][g][i+1]%= MOD;
                }
                if (i==n) {
                    res+= dp[r][g][b];
                    res%= MOD;
                }
            }
        }
    }
    cout << res;
    return 0;
}
