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
    for (size_t i = 0; i < count; i++)
    {
        for (auto &&forr : v)
        {
            for (int i = length - 1; i >= 0; i--)
            {
                /* code */
            }
             
        }
        
    }
     
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n+1);
        FOR(i,1,n) cin >> a[i];
        vector<ll> b;
        FOR(i,1,n) {
            if (!a[i]) continue;
            if (b.empty() || b.back()*a[i] < 0) b.push_back(a[i]);
            else if (a[i] * b.back() > 0) {
                b.back() += a[i];
            }
        }
        int time_elapsed = 0;
        multiset<pair<ll, ll> > S;
        vector<int> Next, Prev, deleted, nChanged;
        Next.resize(b.size());
        Prev.resize(b.size());
        deleted.resize(b.size());
        nChanged.resize(b.size());
        dbg(b.size());
        for(int i=0; i < b.size(); i++){
            Next[i] = i+1,  Prev[i] = i-1;
            S.insert({abs(b[i]), i});
        }
        ll res = 0;
        while (S.size()) {
            auto [val, pos] = *S.begin();
            dbg(val, pos, nChanged[pos]);
            S.erase(S.begin());
            if (deleted[pos]) continue;
            if (nChanged[pos]) {
                nChanged[pos]--;
                continue;
            }
            res= val;
            if (Prev[pos] == -1) {
                if (Next[pos]!=b.size()) Prev[Next[pos]] = Prev[pos];
            }
            else if (Next[pos] == b.size()) {
                Next[Prev[pos]] = Next[pos];
            }
            else {
                Prev[Next[pos]] = Prev[pos];
                Next[Prev[pos]] = Next[pos];
                ll tmp = b[pos] + b[Prev[pos]] + b[Next[pos]];
                S.insert({abs(tmp), Next[pos]});
                b[Next[pos]] = tmp;
                deleted[pos] = true;
                nChanged[Next[pos]]++;
                pos = Prev[pos];
                if (Next[pos]!=b.size()) 
                Prev[Next[pos]] = Prev[pos];
                if (Prev[pos]!=-1)
                Next[Prev[pos]] = Next[pos];
            }
            deleted[pos] = true;
        }
        cout << res << "\n";
    }
    return 0;
}