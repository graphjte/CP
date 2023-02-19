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
const int MOD = 1e9;

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
        vector<int> a(n+1);
        int l = 0, r = MOD;
        FOR(i,1,n) cin >> a[i];
        FOR(i,2,n) {
            if (a[i]==a[i-1]) continue;
            if (a[i] > a[i-1]) {
                int rt = (a[i] + a[i-1])/2;
                r = min(rt, r);
            }
            else l = max((a[i]+a[i-1]+1)/2, l);
        }
        // cout << l << " " << r << "\n";
        if (l > r) cout << -1;
        else cout << l;
        cout << "\n";
    }
    return 0;
}