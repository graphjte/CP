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
    vector<ll> f(MAXN);
    FOR(i,2,MAXN-1) {
        f[i] = f[i-1]*(i) % MOD + ((2*(i-1))% MOD)* i % MOD ;
        f[i] %= MOD;
    }
    while (T--) {
        int n;
        cin >> n;
        cout << f[n] << "\n";
    }
    return 0;
}