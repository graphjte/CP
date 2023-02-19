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
        int n, m;
        cin >> n >> m;
        vector<ii> a(n+1);
        vector<int> used(n+1);
        int sum = 0;
        vector<int> b(n+1);
        FOR(i,1,n) cin >> a[i].fi, a[i].se = i, b[i] = a[i].fi;
        sort(a.begin(), a.end());
        int mx = 0, cnt = 0;
        FOR(i,1,n) {
            if (sum + a[i].fi > m) break;
            sum+= a[i].fi;
            mx = a[i].fi;
            used[a[i].se] = true;
            cnt = i;
        }
        if (cnt == n) cout << 1 << "\n";
        else if (!used[cnt+1] && sum - a[cnt].fi + b[cnt+1] <= m) {
            cout << n - cnt  << "\n";
        }
        else if (used[cnt+1]) cout << n - cnt  << "\n";
        else cout << n - cnt + 1 << "\n";
    }
    return 0;
}