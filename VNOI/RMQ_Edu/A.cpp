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
class SparseTable2D {
 public:
  explicit SparseTable2D(const std::vector<std::vector<T> >& data) {
    int rows = std::log2(data.size()) + 1;
    int cols = std::log2(data[0].size()) + 1;
    mat.resize(data.size());
    for (unsigned i = 0; i < data.size(); i++) {
      mat[i].resize(data[0].size());
      for (unsigned j = 0; j < data[0].size(); j++) {
        mat[i][j].resize(rows, std::vector<T>(cols));
      }
    }
    for (unsigned i = 0; (1u << i) <= data.size(); i++) {
      for (unsigned j = 0; (1u << j) <= data[0].size(); j++) {
        for (unsigned x = 0; x + (1u << i) - 1 < data.size(); x++) {
          for (unsigned y = 0; y + (1u << j) - 1 < data[0].size(); y++) {
            if (i == 0 && j == 0) {
              mat[x][y][i][j] = data[x][y];
            } else if (i == 0) {
              T a = mat[x][y][i][j - 1];
              T b = mat[x][y + (1u << (j - 1))][i][j - 1];
              mat[x][y][i][j] = std::max(a, b);
            } else if (j == 0) {
              T a = mat[x][y][i - 1][j];
              T b = mat[x + (1u << (i - 1))][y][i - 1][j];
              mat[x][y][i][j] = std::max(a, b);
            } else {
              T a = mat[x][y][i - 1][j - 1];
              T b = mat[x + (1u << (i - 1))][y][i - 1][j - 1];
              T c = mat[x][y + (1u << (j - 1))][i - 1][j - 1];
              T d = mat[x + (1u << (i - 1))][y + (1u << (j - 1))][i - 1][j - 1];
              mat[x][y][i][j] = std::max(std::max(a, b), std::max(c, d));
            }
          }
        }
      }
    }
  }

  T query(int row_from, int row_to, int col_from, int col_to) const {
    unsigned k = std::log2(row_to - row_from + 1);
    unsigned l = std::log2(col_to - col_from + 1);
    T a = mat[row_from][col_from][k][l];
    T b = mat[row_to - (1u << k) + 1][col_from][k][l];
    T c = mat[row_from][col_to - (1u << l) + 1][k][l];
    T d = mat[row_to - (1u << k) + 1][col_to - (1u << l) + 1][k][l];
    return std::max(std::max(a, b), std::max(c, d));
  }

 private:
  std::vector<std::vector<std::vector<std::vector<T> > > > mat;
};

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    ll n, q;
    cin >> n >> q;
    vector<vector<ll> > x(6, vector<ll>(q+1));
    vector<ll> M(6);
    cin >> x[0][0] >> x[1][0];
    cin >> x[2][0] >> x[3][0] >> x[4][0] >> x[5][0];
    M[1] = M[0] = M[2] = MOD;
    M[3] = M[4] = M[5] = n;
    FOR(i,1,q) {
        FOR(j,0,5) {
            if (i==1) x[j][i] = 1 + (x[j][i-1]*x[j][i-1]) % M[j];
            else x[j][i] = 1 + (x[j][i-1]+x[j][i-2]) % M[j];
        }
    }
    vector<vector<ll> > a(n*2, vector<ll>(n*2));
    FOR(i,0,n*2-1)
        FOR(j,0,n*2-1) {
            a[i][j] = (x[0][(i%n)+1] + x[1][(j%n)+1]) % MOD;
            if (i < n && j < n) {
                cout << a[i][j] << " \n"[j==n-1];
            }
        }
    SparseTable2D<ll> st(a);
    ii top_left = {0,0};
    vector<ll> ans;
    FOR(i,1,q) {
        if (x[2][i]&1) {
            top_left.first = (top_left.first + x[4][i] + n) % n;
            top_left.second = (top_left.second + x[3][i] + n) % n;
        }
        else {
            ll L = n - max(x[3][i], x[4][i]);
            ll X = x[3][i], Y = x[4][i], D = 1 + (L&(L^x[5][i]));
            ll row_from = (Y-1 + top_left.first) % n;
            ll col_from = (X-1 + top_left.second) % n;
            ll row_to = row_from + D - 1;
            ll col_to = col_from + D - 1;
            ans.push_back(st.query(row_from, row_to, col_from, col_to));
            cout << top_left.first << " " << top_left.second << "\n";
            cout << ans.back()<< "\n";
        }
    }
    int res = 0;
    for(int i = 0; i < ans.size(); i++) {
        if ((i == ans.size()-1) || (i%1000 == 999)) {
            cout << res << "\n";
            res = 0;
        }
        else {
            res+= ans[i];
            res%= MOD;
        }
    }
    return 0;
}