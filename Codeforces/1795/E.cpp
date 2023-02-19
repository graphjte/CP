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

void Solve() {
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n+3), b(n+3), L(n+3), sb(n+3), R(n+3), fL(n+3), fR(n+3);
    FOR(i,1,n) cin >> a[i], sum+= a[i];
    FOR(i,1,n) b[i] = a[i] + i, sb[i] = sb[i-1] + b[i];
    stack<int> st;
    st.push(n+1);
    dbg(b);
    FORD(i,n,1) {
        while (b[st.top()] > b[i]) st.pop();
        R[i] = st.top();
        st.push(i);
    }
    dbg(sb);
    FORD(i,n,1) {
        fR[i] = fR[R[i]] + sb[R[i] - 1] - sb[i-1] - b[i] * (R[i]-1 - i+1);
        dbg(i, sb[i-1], sb[R[i]-1], b[i], (R[i]- i));
    }

    dbg(R);
    FOR(i,1,n) b[i] = a[i] + (n-i+1), sb[i] = sb[i-1] + b[i];
    while (st.size()) st.pop();
    st.push(0);
    FOR(i,1,n) {
        while (b[st.top()] > b[i]) st.pop();
        L[i] = st.top();
        st.push(i);
    }
    
    FOR(i,1,n) {
        fL[i] = fL[L[i]] + sb[i] - sb[L[i]] - b[i] * (i - L[i]);
    }
    vector<ll> res(n+3);
    ll ans = LLONG_MAX;
    vector<ll> incSeq(n+3), remL(n+3), remR(n+3);
    FOR(i,1,n) {
        R[i] = min((ll)n,i + a[i]);
        L[i] = max(1ll, i - a[i]);
        L[i] = max(L[i], L[i-1]);
        incSeq[i] = incSeq[i-1] + i;
    }
    FORD(i,n-1,1) R[i] = min(R[i], R[i+1]);
    FOR(i,1,n) {
        remR[i] = incSeq[n - R[i]];
        remL[i] = incSeq[L[i]-1];
    }
    dbg(L, R);
    dbg(remL, remR);
    FOR(i,1,n) res[i] =  fL[i] + fR[i] + a[i] - remR[i] - remL[i], ans = min(ans, res[i]);
    dbg(remR[5]);
    cout << ans << "\n";
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int T = 1;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}