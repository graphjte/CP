//https://codeforces.com/contest/1790/problem/F
#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAXN = 2e5+6;
const int MOD = 1e9+7;

int depth[MAXN];

template<class T> 
class Min{
  public:
  T operator()(const T &a, const T &b) const{
    if (depth[a] < depth[b]) return a;
    else return b;
  }
};

template <class T, class Op>
class SparseTable {
 public:
  explicit SparseTable(const std::vector<T>& arr) {
    lookup.resize(arr.size(), std::vector<T>(std::log2(arr.size()) + 1));
    for (unsigned i = 0; i < arr.size(); i++) { lookup[i][0] = arr[i]; }
    for (unsigned j = 1; (1u << j) <= arr.size(); j++) {
      for (unsigned i = 0; i + (1u << j) - 1 < arr.size(); i++) {
        lookup[i][j] = op(lookup[i][j - 1], lookup[i + (1u << (j - 1))][j - 1]);
      }
    }
  }
  SparseTable() {}

  int query(int left, int right) const {
    unsigned j = std::log2(right - left + 1);
    return op(lookup[left][j], lookup[right - (1u << j) + 1][j]);
  }

 private:
  Op op;
  std::vector<std::vector<T> > lookup;
};

SparseTable<int, Min<int> > st;
int n, pos[MAXN], c[MAXN], isBlack[MAXN], minDistance[MAXN];
vector<int> E;
vector<int> g[MAXN];

void Reset() {
    FOR(i,0,n) {
        pos[i] = 0;
        g[i].clear();
        isBlack[i] = 0;
        minDistance[i] = MOD;
    }
    E.clear();
}

void DFS(int u, int par) {
    E.push_back(u);
    depth[u] = depth[par] + 1;
    if (!pos[u]) pos[u] = E.size() - 1;
    for(auto &v: g[u]) {
        if (v==par) continue;
        DFS(v, u);
        E.push_back(u);
    }
}

int LCA(int u, int v) {
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);
    return st.query(u, v);
}

void buildDistances() {
    FOR(i,1,n) minDistance[i] = MOD;
    queue<int> q;
    FOR(i,1,n) {
        if (isBlack[i]) {
            q.push(i);
            minDistance[i] = 0;
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for(auto &v: g[u]) {
            if (minDistance[v] == MOD) {
                minDistance[v] = 1 + minDistance[u];
                q.push(v);
            }
        }
    }
}

void Solve() {
    cin >> n;
    Reset();
    cin >> c[0];
    FOR(i,1,n-1) cin >> c[i];
    FOR(i,1,n-1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS(1,0);
    st = SparseTable<int, Min<int> >(E);

    vector<int> answers(n+1);
    vector<int> currentBlock;
    answers[0] = MOD;
    currentBlock.push_back(c[0]);
    isBlack[c[0]] = true;
    int blockSize = ceil(sqrt(n));
    FOR(i,1,n-1) {
        if (answers[i-1] == 1) {
            answers[i] = 1;
            continue;
        }
        if (i/blockSize != (i-1)/blockSize) {
            currentBlock.clear();
            buildDistances();
        }
        int tmp = INT_MAX;
        for(auto &x: currentBlock) {
            tmp = min(tmp, depth[c[i]]- 2*depth[LCA(c[i], x)] + depth[x]);
        }
        answers[i] = min({answers[i-1], tmp, minDistance[c[i]]});
        isBlack[c[i]] = true;
        currentBlock.push_back(c[i]);
    }
    FOR(i,1,n-1) cout << answers[i] << " ";
    cout << "\n";
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