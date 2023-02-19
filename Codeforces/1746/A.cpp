#include <bits/stdc++.h>
#define fi first
#define se second
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define ii pair<int, int>
using namespace std;

const int MAX = 2e5 + 6;
const int MOD = 1e9 + 7;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
  }

  int T;
  cin >> T;
  while (T--) {
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> a(n + 3);
    FOR(i, 1, n) {
      cin >> a[i];
      sum += a[i];
    }
    if (!sum) {
      cout << "NO\n";
    } else
      cout << "YES\n";
  }
  return 0;
}
