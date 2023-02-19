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
        int n;
        cin >> n;
        vector<ll> a(n+1), b(n+1), s(n+3), r(n+3), rem(n+3);
        FOR(i,1,n) cin >> a[i]; 
        FOR(i,1,n) cin >> b[i]; 
        FOR(i,1,n) s[i] = s[i-1] + b[i];
        s[n+1] = 1e15;
        FOR(i,1,n) {
            //a[i] -> upperbound(i, n, a[i] + s[i-1]) prev
            //pos+1 += a[i] - sum[]
            int tmp = upper_bound(s.begin() + i, s.begin() + n +2, a[i] + s[i-1]) - s.begin() - 1;
            ll sum = s[tmp] - s[i-1];
            sum = a[i] - sum;
            rem[tmp+1] += max(0ll, sum);
            //[i, tmp] -> 1
            r[i]++; r[tmp+1]--;
            dbg(i, tmp);
        }
        FOR(i,1,n+1) r[i]+= r[i-1];
        dbg(r);
        FOR(i,1,n) {
            rem[i] += r[i] * b[i];
            cout << rem[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}