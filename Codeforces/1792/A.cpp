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
        int n, ans = 0;
        cin >> n;
        vector<int> a(n+1);
        FOR(i,1,n) {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.end());
        for(int i=1; i<=n; i++) {
            if (i < n && a[i] == a[i+1] && a[i+1] == 1) {
                ans++;
                i++;
            }
            else {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}