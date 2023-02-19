#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAXN = 5e5+6;
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

struct node
{
	int prefix_count;
	bool isEnd;
	struct node *child[11];
}*head;

void init()
{
	head = new node();
	head->isEnd = false;
	head->prefix_count = 0;
}

void insert(vector<int> word)
{
	node *current = head;
	current->prefix_count++;
	
	for(int i = 0 ; i < word.size(); ++i)
	{
		int letter = (int)word[i];	//extrct first character of word
		if(current->child[letter] == NULL)
			current->child[letter] = new node();

		current->child[letter]->prefix_count++;
		current = current->child[letter];		
	}
	current->isEnd = true;
}

int search(vector<int> word)
{
    int cnt = 0;
	node *current = head;
	for(int i = 0 ; i < word.size(); ++i)
	{
		int letter = (int)word[i];
		if(current->child[letter] == NULL)
			return cnt;		//not found
		current = current->child[letter];
        cnt++;
        dbg(word[i], cnt);
	}
	return cnt;
}

int words_with_prefix(vector<int> prefix)
{
	node *current = head;
	for(int i = 0; i < prefix.size() ; ++i)
	{
		int letter = (int)prefix[i] - (int)'a';
		if(current->child[letter] == NULL)
			return 0;
		else
			current = current->child[letter];
	}
	return current->prefix_count;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int> > a(n, vector<int>(m));
        vector<int> pos(m);
        vector<vector<int> > b(n, vector<int>(m));
        init(); 
        FOR(i,0, n-1) {
            FOR(j,0, m-1) {
                cin >> a[i][j];
                a[i][j]--;
                pos[a[i][j]] = j;
            }
            FOR(j,0,m-1) {
                b[i][j] = pos[j];
            }
            dbg(a[i]);
            dbg(b[i]);
            insert(b[i]);
        }
        vector<int> ans(n);
        FOR(i,0,n-1) {
            ans[i] = search(a[i]);
        }
        for(auto &x: ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}