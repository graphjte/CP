#include <bits/stdc++.h>
#define int long long
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

int32_t main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n+3);
        FOR(i,1,n) {
            cin >> a[i];
        }
        sort(a.begin() + 2, a.begin() + n + 1);
        FOR(i,2,n) {
            if (a[i] <= a[1]) continue;
            else {
                int tmp = (a[1] + a[i]) ;
                a[1] = tmp - (tmp)/2;
            }
        }
        cout << a[1] << "\n";
    }
    return 0;
} 