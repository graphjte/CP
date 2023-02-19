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
// const int MOD = 1e9+7;
const int MOD =   998244353;

int pow(int x) {
    if (x==1) return 2;
    if (x==0) return 1;
    ll ret = pow(x/2);
    ret = (ret*ret)% MOD;
    if (x&1) ret = (ret*2)%MOD;
    return ret;
}

int main(int argc, char const *argv[])
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
        string s;
        cin >> s;
        s = " " + s;
        int max_suf = 0;
        ll res = 0;
        FOR(i,1,n) {
            if (s[i]==s[i-1]) max_suf++;
            else max_suf = 1;
            res+= pow(max_suf-1);
            res%= MOD;
        }
        cout << res << "\n";
    }
    return 0;
}