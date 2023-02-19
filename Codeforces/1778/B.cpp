#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
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
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> a(n+1), b(m+1), pos(n+1);
        FOR(i,1,n) cin >> a[i], pos[a[i]] = i;
        FOR(i,1,m) cin >> b[i];
        int ans = INT_MAX;
        FOR(i,2,m) {
            int L = pos[b[i-1]], R = pos[b[i]];
            // cerr << L << " " << R << "\n";
            if (R < L || L + d < R) {
                ans = 0;
                continue;
            }
            ans = min(ans, R - L);
            if (d + 2 <= n) {
                // cerr << L + d + 1 << "\n";
                ans = min(ans, L + d + 1 - R);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}