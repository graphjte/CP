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

    int T;
    cin >> T;
    while (T--) {
        int n, res = INT_MAX;
        ll s = 0;
        cin >> n;
        vector<int> a(n+1);
        for(int i=1; i<=n; i++) cin >> a[i], s+= a[i];
        if (s&1) {
            FOR(i,1,n) {
                int cnt = 0;
                if (a[i]&1) {
                    while ((a[i]&1) && cnt < 100) {
                        a[i]/=2;
                        cnt++;
                    }
                }
                else {
                    while (a[i]%2==0 && cnt < 100) {
                        a[i]/=2;
                        cnt++;
                    }
                }
                res = min(res, cnt);
            }
            cout << res << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
    return 0;
}