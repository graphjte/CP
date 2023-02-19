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
    
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//64-bit number generator
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n+2);
        //n/2 
        a[n+1] = 1;
        FOR(i,1,n) a[i] = i;
        for(int i=1; i<=n; i++) {
            cout << "? " << a[i] << " " << a[i+1] << endl;
            int x;
            cin >> x;
            f[a[i]] = max(f[a[i]], x);
            f[a[i+1]] = max(f[a[i+1]], x);
        }
        
    }
    return 0;
} 