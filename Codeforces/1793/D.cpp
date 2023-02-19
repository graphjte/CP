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

int n;

vector<pair<ii, ii> > Calc(vector<int> &a, vector<int> &pos) {
    //2->n
    int l = pos[1], r = pos[1];
    vector<pair<ii, ii> > ans;
    FOR(i,2,n) {
        int x = pos[i];
        if (l<=x && x<=r) {
            ans.push_back({{-1,-1}, {-1,-1}});
        }
        else if (r < x) {
            ans.push_back({{1, l}, {r,x-1}});
        }
        else {
            ans.push_back({{x+1, l}, {r, n}});
        }
        l = min(l, pos[i]);
        r = max(r, pos[i]);
    } 
    return ans;
}

ll C2(int x) {
    return 1ll * x * (x-1) / 2 + x;
}

ll Count(pair<ii, ii> r1, pair<ii, ii> r2) {
    auto [L1, R1] = r1;
    auto [L2, R2] = r2;
    if (L1.fi == -1 || L2.fi == -1) {
        return 0;
    }
    dbg(L1, R1, L2, R2);
    L1.fi = max(L1.fi, L2.fi);
    L1.se = min(L1.se, L2.se);
    R1.fi = max(R1.fi, R2.fi);
    R1.se = min(R1.se, R2.se);
    return max(0ll,(ll)R1.se - R1.fi + 1) * max(0ll,(ll)L1.se - L1.fi + 1);
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> n;
    vector<int> a(n+1), b(n+1), pos_a(n+1), pos_b(n+1);  
    FOR(i,1,n) {
        cin >> a[i];
        pos_a[a[i]] = i;
    }
    FOR(i,1,n) {
        cin >> b[i];
        pos_b[b[i]] = i;
    }
    vector<pair<ii, ii> > r1 = Calc(a, pos_a);
    vector<pair<ii, ii> > r2 = Calc(b, pos_b);
    ll res = 0;
    for(int i = 0; i < r1.size(); i++) {
        res+= Count(r1[i], r2[i]);
    }
    int x = pos_a[1];
    int y = pos_b[1];
    if (x < y) swap(x, y);
    res+= C2(y-1) + C2(n-x);
    res+= C2(x -1 - y);
    dbg(y-1, n-x);
    dbg(pos_a);
    cout << res +1<< "\n";
    return 0;
}