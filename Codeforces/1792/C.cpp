#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAXN = 2e5+6;
const int MOD = 1e9+7;

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

class fenwick_tree
{
private:
    vector<long long> data;
    int tree_size;

public:
    fenwick_tree(int tree_size = 0)
    {
        this->tree_size = tree_size;
        data.resize(tree_size + 1);
    }
    ~fenwick_tree() {}
    void update(int pos, long long val)
    {
        for (; pos <= tree_size; pos += pos & -pos)
            data[pos] = max(data[pos], val);
    }
    long long query(int pos)
    {
        long long ret = 0;
        for (; pos > 0; pos -= pos & -pos)
            ret = max(ret, data[pos]);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int T = 1;
    cin >> T;
    while (T--) {
        int n, bad = 0;
        cin >> n;
        vector<int> pos(n+1), a(n+1);
        FOR(i,1,n) {
            cin >> a[i]; 
            pos[a[i]] = i;
        }
        int tmp = 0;
        int prev_i = n+1, prev_j = -1;
        for(int i = (n+1)/2, j = i + (n%2==0); i> 0 && j <=n; i--, j++) {
            if (pos[i]<= pos[j] && prev_i >= pos[i] && prev_j <= pos[j]) {
                prev_i = pos[i];
                prev_j = pos[j];
                tmp++;
                dbg(i, j);
                dbg(prev_i, prev_j);
            }
            else break;
        }
        cout << (n+1)/2 - tmp << "\n";
    }
    return 0;
}