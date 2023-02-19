#include <iostream>
#include <vector>
using namespace std;

int main() {
  int k = 0;
  int n = 5;
  vector<int> a(3);
  for (int i = 0; i < n; i++) {
    k++;
  }
  sort(a.begin(), a.end());
  cout << a[-1];
  return 0;
}
