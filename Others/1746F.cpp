//https://codeforces.com/contest/1746/problem/F
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
#endif

const int MAX = 3e5+6;
const int MOD = 1e9+7;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= s.size() && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

int n, q;
int a[MAX];
vector<int> B;
vector<tuple<int, int, int> > Q;
vector< vector<bool> > S;

int compressedValue(int x) {
    return lower_bound(B.begin(), B.end(), x) - B.begin() + 1;
}

void generateSubsets() {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//64-bit number generator
    S.resize(30);
    FOR(i,0, 30 - 1) {
        S[i].resize(B.size()+6, 0);
        FOR(j,0, S[i].size()-1) {
            S[i][j] = rng() % 2;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> n >> q;
    FOR(i,1,n) cin >> a[i], B.push_back(a[i]);
    FOR(i,1,q) {
        int Type;
        cin >> Type;
        if (Type==1) {
            int pos, x;
            cin >> pos >> x;
            Q.push_back({0, pos, x});
            B.push_back(x);
        }
        else {
            int l, r, k;
            cin >> l >> r >> k;
            Q.push_back({l, r, k});
        }
    }
    sort(B.begin(), B.end());
    FOR(i,1,n) a[i] = compressedValue(a[i]);

    generateSubsets();


    vector<FT> ft(30, FT(n + 10));
    for(int i = 0 ; i < 30; i ++) {
        for(int j = 1; j <=n; j++) {
            if (S[i][(a[j])]) {
                ft[i].update(j, 1);
            }
        }
    }

    for(auto &query: Q) {
        if (get<0>(query) == 0) {
            auto [_, i, x] = query;
            x = compressedValue(x);
            for(int j = 0; j < 30; j++) {
                if (S[j][(a[i])] == S[j][x]) continue;
                else if (S[j][(a[i])]) {
                    ft[j].update(i, -1);
                }
                else {
                    ft[j].update(i, 1);
                }
            }
            a[i] = x;
        }
        else {
            auto [l, r, k] = query;
            bool ans = true;
            r++; l++;
            for(int i = 0; i < 30; i++) {
                if ((ft[i].query(r) - ft[i].query(l-1)) % k != 0) ans = false;
            }
            if (ans) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
    vector<int> x = {1, 2, 3};
    set<int> y = {1, 2, 3};
    stack<int> z;
    z.push(3);
    z.push(2);
    z.push(3);
    dbg(x, y, z.top());
    return 0;
}