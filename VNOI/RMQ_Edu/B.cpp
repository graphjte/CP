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

template <class T>
class SparseTable {
 public:
  explicit SparseTable(const std::vector<T>& arr, function<T(T, T)> _op) {
    op = _op;
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
  std::vector<std::vector<T> > lookup;
  function<T(T, T)> op;
};

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    vector<int> Prev(n+1);
    vector<int> Next(n+1, n+1);
    FOR(i,1,n) cin >> a[i];
    map<int, int> last;
    //max prev, min next
    FOR(i,1,n) {
        Prev[i] = last[a[i]];
        last[a[i]] = i;
    }
    last.clear();
    FORD(i,n,1) {
        if (last[a[i]]) Next[i] = last[a[i]];
        last[a[i]] = i;
    }
    FOR(i,1,n) {
      // cout << Prev[i] << " " << Next[i] << "\n";
    }

    SparseTable<int> L(Prev, [&](int a, int b){return max(a, b);}); 
    SparseTable<int> R(Next, [&](int a, int b){return min(a, b);}); 

    FOR(i,1,q) {
        int l, r;
        cin >> l >> r;
        cout << max(0, min(r, R.query(l,r)) - max(l, L.query(l,r))) << "\n";
    }
    return 0;
}