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
    
    int T = 1;
    fac[0] = 1;
    FOR(i,1,MAX-1) fac[i] = (fac[i-1]*i) % MOD;
    cin >> T;
    while (T--) {
        int n, i, j, x, y; //a[i] = x, a[j] = y
        cin >> n >> i >> j >> x >> y;
        if (x > y) {
            swap(x, y);
            int I = i, J = j;
            i = n-J+1; j = n-I+1;
        }
        if (y==n) {
            if (j==n) {
                cout << "0\n";
            }
            else cout << (C(i-1, x-1) * C(j-i-1, n-1-x)) % MOD << "\n";
            continue;
        } 
        ll res = 0;
        FOR(center, i+1, j-1) {
            ll tt = x-i;
            ll tmp = (C(i-1, x-1) * C(n-j-tt, y-x-1)) % MOD;//x+1, y-1
            if (tt < 0) tmp = 0;
            // cout << i-1 << " " << x-1 << " " << n-j << " " << y-x-1 << "\n";
            // cout << j-center-1 << " " << n-y-1 << "\n";
            tmp*= C(j-center-1,n-1-y); //y+1->n-1 , chooses j - center-1 elements
            tmp%= MOD;
            res+= tmp;
            res%= MOD;
        }
        FOR(center, j+1, n-1) {
            ll tmp = C(i-1, x-1) * C(j-i-1, y-x-1); //x+1->y-1, chooses j-i-1 elements
            tmp%= MOD;
            tmp*= C(center-j-1,n-1-y); //y+1->n-1 , chooses j - center-1 elements
            tmp%= MOD;
            res+= tmp;
            res%= MOD;
        }
        cout << res << "\n";
    }
    return 0;
}