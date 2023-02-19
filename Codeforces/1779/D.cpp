#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e9+7;

template<class T> 
class Max{
  public:
  T operator()(const T &a, const T &b) const{
      return max(a,b);
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

  int query(int left, int right) const {
    unsigned j = std::log2(right - left + 1);
    return op(lookup[left][j], lookup[right - (1u << j) + 1][j]);
  }

 private:
  Op op;
  std::vector<std::vector<T> > lookup;
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
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1);
        map<int, int> Last;
        vector<int> Prev(n+1);
        FOR(i,1,n) Prev[i] = i;
        FOR(i,1,n) cin >> a[i];
        FOR(i,1,n) {
            cin >> b[i];
            if (a[i]==b[i]) continue;
            if (Last[b[i]]) Prev[i] = Last[b[i]];
            Last[b[i]] = i;
        }
        int m;
        cin >> m;
        vector<int> c(m+1);
        map<int, int> M;
        FOR(i,1,m) cin >> c[i], M[c[i]]++;
        sort(c.begin()+1, c.end());
        vector<int> res;
        SparseTable<int, Max<int> > st(b);
        FOR(i,1,n) {
            if (a[i]==b[i]) continue;
            else {
                if (a[i] < b[i]) res.push_back(-1);
                else {
                    if (i!= Prev[i] && st.query(Prev[i], i) <= b[i]) {
                        continue;
                    }
                    else res.push_back(b[i]);
                }
            }
        }
        bool bad = false;
        for(auto &x: res) {
            // cout << x << " ";
            if (M[x] <= 0) bad = true;
            else M[x]--;
        }
        if (bad) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}