#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

double d[1000006], a[1000006];
int n, len[1000006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    vector<int> s; d[0] = -1e9;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];

        if (d[i-1] <= a[i]) {
            s.push_back(i-1);
            len[i] = 1;
            d[i] = a[i];
        } else {
            len[i] = len[i-1] + 1;
            d[i] = (d[i-1] * len[i-1] + a[i]) / len[i];

            while (d[i] < d[s.back()]) {
                d[i] = (d[i] * len[i] + d[s.back()] * len[s.back()]);
                len[i] += len[s.back()];
                d[i] /= len[i];
                s.pop_back();
            }
        }
    }

    for(int i = n - 1; i >= 1; --i)
    if (d[i] > d[i+1]) d[i] = d[i+1];

    double ans = 0;
    for(int i = 1; i <= n; ++i) ans += (a[i] - d[i]) * (a[i] - d[i]);

    (cout << fixed).precision(10);
    cout << sqrt(ans);

    return 0;
}
