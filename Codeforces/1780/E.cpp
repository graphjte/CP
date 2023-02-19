#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
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

const int MAXN = 3e5+6;
const int MOD = 1e9+7;

int lpf[MAXN], nDivisors[MAXN], aMax, n;
vector<int> a;
unordered_map<int, int> pos;
vector<int> factors[MAXN];

void Sieve() {
    FOR(i,2,MAXN - 1) {
        if (!lpf[i]) {
            for(int j = i; j<MAXN; j+=i) {
                factors[j].push_back(i);
                lpf[j] = i;
            }
        }
    }
}

void Solve() {
    vector<vector<int>> g(aMax + 1); //g[i] is a vector contains all positions which value divisible by i
    FOR(i,1,n) {
        for(auto &factor: factors[a[i]]) {
            g[factor].push_back(i);
        }
    }


    ll curSum = 0;
    FOR(i,2,aMax) {
        int cnt = 0;
        int sign = factors[i].size() &1 ? 1 : -1;
        dbg(i, factors[i]);
        for(auto &x: g[i]) {
            ll R = g[i].size() - cnt - 1;
            ll L = cnt;
            curSum -= 1ll*R * (x + 1) * sign;
            curSum += 1ll*(L) * x * sign;
            cnt++;
        }
        dbg(curSum);
    }
    ll total = 0;
    total = n * (n-1) * (n-2);
    total/= 6;
    cout << total - curSum << "\n";
    // cout << curSum << "\n";
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int T = 1;
    Sieve();
    // cin >> T;
    while (T--) {
        cin >> n;
        aMax = 0;
        a.resize(n+1);
        pos.clear();
        FOR(i,1,n) cin >> a[i], aMax = max(aMax, a[i]);
        sort(a.begin() + 1, a.end());
        FOR(i,1,n) pos[a[i]] = i;
        Solve();
    }
    return 0;
}