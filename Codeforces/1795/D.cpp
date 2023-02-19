#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define FOR(i,a,b) for (int i=(int)a; i<=(int)b; ++i)
#define FORD(i,b,a) for (int i=(int)b; i>=(int)a; --i)
using namespace std;

//Template for debugging
#ifndef ONLINE_JUDGE
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c) {
os << '[';
for (auto it = c.begin(); it != c.end(); ++it)
os << &", "[2 * (it == c.begin())] << *it;
return os << ']';
}
//support up to 5 args
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                             \
_NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0)     \
(MACRO, ##__VA_ARGS__)
//Change output format here
#define watch(x) cerr << "\033[1;32m" #x " = \033[1;34m" << (x) << "\033[0m; ";
#define dbg(...)                                                              \
    cerr << "\033[2;31mLine " << __LINE__ << ": \033[0;m"; \
    FOR_EACH_MACRO(watch, __VA_ARGS__)                     \
    cerr << endl
#else
#define dbg(...)
#define watch(...)
#endif

const int MAXN = 2e5+6;
const int MOD = 998244353;

ll powMod(ll a, ll k) {
    if (k==0) return 1ll;
    ll tmp = powMod(a, k/2);
    tmp = (tmp*tmp) % MOD;
    if (k&1) tmp = tmp*a;
    tmp%= MOD;
    return tmp;
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int n;
    cin >> n;
    vector<ll> a(n+1), gt(n+1), cnt(n+1);
    gt[0] = 1;
    FOR(i,1,n) {
        cin >> a[i];
        gt[i] = gt[i-1] * i;
        gt[i] %= MOD;
    }
    ll sum = 0, r1=1;
    for(int i = 3; i<=n; i+=3) {
        sum%= MOD;
        vector<ll> s = {a[i], a[i-1], a[i-2]};
        sort(s.begin(), s.end());
        if (s[0] == s[1] && s[1] == s[2]) cnt[i] = 3;
        else if (s[0] == s[1]) cnt[i] = 2;
        else cnt[i] = 1;
        r1*= cnt[i];
        r1%= MOD;
    }
    n/=3;
    dbg(gt);
    ll res = gt[n] * powMod(gt[n/2], MOD-2) % MOD * powMod(gt[n/2], MOD-2) % MOD;
    dbg(powMod(gt[n/2], MOD-2));
    cout << res*r1 % MOD;
    return 0;
}