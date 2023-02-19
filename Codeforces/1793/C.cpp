#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define FOR(i,a,b) for (int i=(int)a; i<=(int)b; ++i)
#define FORD(i,b,a) for (int i=(int)b; i>=(int)a; --i)
using namespace std;

const int MAXN = 2e5+6;
const int MOD = 1e9+7;

template<class T> 
class Min{
  public:
  T operator()(const T &a, const T &b) const{
      return min(a,b);
  }
};
template<class T> 
class Max   {
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
        vector<int> a(n+1);
        FOR(i,1,n) cin >> a[i];
        SparseTable<int, Min<int> > stMin(a);
        SparseTable<int, Max<int> > stMax(a);
        int l = 1, r = n;
        while (l <= r) {
            int x = stMin.query(l,r);
            int y = stMax.query(l,r);
            int flag = 0;
            if (a[l] == x || a[l] == y) {
                l++;
                flag = 1;
            }
            if (a[r] == x || a[r] == y) {
                r--;
                flag = 1;
            }
            if (!flag) break;
        }
        if (l > r) {
          cout << -1 <<"\n";
        }
        else cout << l << " " << r << "\n";
    }
    return 0;
}