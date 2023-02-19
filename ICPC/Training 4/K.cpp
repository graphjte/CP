
#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
typedef vector<vector<llong>> matrix;

matrix I;
int n;

matrix operator * (const matrix &A, const matrix &B) {
    matrix C(n, vector<llong>(n, 0));

    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
    for(int m = 0; m < n; ++m) (C[i][j] += (A[i][m] * B[m][j]) % mod) %= mod;

    return C;
}

matrix Power(matrix a, int k) {
    matrix res = I;

    while (k > 0) {
        if (k & 1) res = res * a;
        a = a * a;
        k >>= 1;
    }

    return res;
}

char c[106][106];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int h, w, k; cin >> h >> w >> k;
    n = h * w;

    I.assign(n, vector<llong>(n, 0));
    matrix a(n, vector<llong>(n, 0));

    for(int i = 0; i < n; ++i) I[i][i] = 1;

    for(int i = 0; i < h; ++i)
    for(int j = 0; j < w; ++j)
        cin >> c[i][j];

    for(int i = 0; i < h; ++i)
    for(int j = 0; j < w; ++j) {
        if (c[i][j] == '+') {
            if (j > 0 && c[i][j-1] != '#') a[i * w + j][i * w + j - 1] = 1;
            if (j < w - 1 && c[i][j+1] != '#') a[i * w + j][i * w + j + 1] = 1;
            if (i > 0 && c[i-1][j] != '#') a[i * w + j][(i - 1) * w + j] = 1;
            if (i < h - 1 && c[i+1][j] != '#') a[i * w + j][(i + 1) * w + j] = 1;
        } else if (c[i][j] == 'R') {
            if (j < w - 1 && c[i][j+1] != '#') a[i * w + j][i * w + j + 1] = 1;
        } else if (c[i][j] == 'L') {
            if (j > 0 && c[i][j-1] != '#') a[i * w + j][i * w + j - 1] = 1;
        } else if (c[i][j] == 'U') {
            if (i > 0 && c[i-1][j] != '#') a[i * w + j][(i - 1) * w + j] = 1;
        } else {
            if (i < h - 1 && c[i+1][j] != '#') a[i * w + j][(i + 1) * w + j] = 1;
        }
    }

    a = Power(a, k);

    llong ans = 0;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j) (ans += a[i][j]) %= mod;

    cout << ans;

    return 0;
}
