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
    vector<int> factor(MAXN);
    FOR(i,2,MAXN-1) {
        if (!factor[i])
        for(int j = i+i; j< MAXN; j+= i) {
            factor[j] = i;
        }
    }
    auto factorize = [&] (int x) -> vector<int> {
        if (!x) return vector<int>(0);
        vector<int> res;
        for(int i = 1; i * i <= x; i++) {
            if (x%i == 0) {
                res.push_back(i);
                res.push_back(x/i);
            }
        }
        return res;
        // while (factor[x]) {
        //     res.push_back(factor[x]);
        //     x/= factor[x];
        // }
        // if (x) res.push_back(x);
        // res.push_back(1);
        // return res;
    };

    vector<int> tmp = factorize(6);
    dbg(tmp);
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n+1);
        unordered_map<int, int> cnt;
        set<int> S;
        FOR(i,1,n) {
            cin >> a[i];
        }
        int res = MOD;
        sort(a.begin() + 1, a.end());
        int r = 0;
        FOR(l,1,n) {
            auto factors = factorize(a[l-1]);
            for(auto x: factors) {
                if (x > m) continue;
                cnt[x]--;
                if (!cnt[x]) {
                    S.erase(x);
                }
            }
            while (S.size() < m && r < n) {
                ++r;
                factors = factorize(a[r]);
                for(auto &x: factors) {
                    if (x > m) continue;
                    if (!cnt[x]) {
                        S.insert(x);
                    }
                    cnt[x]++;
                }
            }
            if (S.size() == m) res = min(res, a[r] - a[l]);
            dbg(S);
            dbg(l, r);
        }
        if (res==MOD) {
            cout << -1 << "\n";
        }
        else cout << res << "\n";
    }
    return 0;
}