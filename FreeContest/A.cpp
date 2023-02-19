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

ll fac[MAX], n;
 
ll power(ll x, ll k) {
    if (k==1) return x;
    if (k==0) return 1;
    ll ret = power(x, k/2);
    ret = (ret*ret) % MOD;
    if (k&1) ret = ret * x % MOD;
    return ret;
}
 
ll C(ll k, ll n) {
    if (k==0) return 1;
    if (k > n) return 0;
    if (k < 0) return 0;
    return fac[n] * power(fac[k], MOD-2) % MOD * power(fac[n-k], MOD-2) % MOD; 
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    fac[0] = 1; 
    for(int i=1; i <MAX; i++) fac[i] = (fac[i-1]*i) % MOD;
    vector<int> a(3);
    for(int i=0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());

    ll ans = C(a[1], a[0]); 
    return 0;
}