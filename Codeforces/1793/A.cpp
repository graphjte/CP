#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define FOR(i,a,b) for (int i=(int)a; i<=(int)b; ++i)
#define FORD(i,b,a) for (int i=(int)b; i>=(int)a; --i)
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
        ll a, b, m, n; 
        cin >> a >> b >> n >> m;
             ll A = 
             n/(m+1)*a*(m) + n % (m+1) * min(a, b);
             ll B = min(a, b) * n;

        cout << min(A, B)  << "\n";
    }
    return 0;
}