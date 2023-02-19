#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAXN = 40+6;
const int MAXS = MAXN * MAXN;
const int MOD = 1e9+7;
const double EPS  = 1e-9;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int n, m;
int a[MAXN][MAXN], ans[MAXN][MAXN], label[MAXN][MAXN], idx[MAXN][MAXN];

bool valid(int x, int y) {
    return (x > 0 && y > 0 && x <= n && y<=m);
}

int gauss (vector < vector<double> > a, vector<double> & ans, int n, int m) {
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return MOD;
    return 1;
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> n >> m;
    FOR(i,1,n) {
        FOR(j,1,m) {
            cin >> a[i][j];
            ans[i][j] = -1;   
        }
    }
    FOR(i,1,n) {
        FOR(j,1,m) {
            if (a[i][j] == 4) {
                FOR(t,0,3) {
                    int x = i + dx[t], y = j + dy[t];
                    if (!valid(x, y)) continue;
                    ans[x][y] = 1;
                }
            }
            else if (a[i][j] == 0) {
                FOR(t,0,3) {
                    int x = i + dx[t], y = j + dy[t];
                    if (!valid(x, y)) continue;
                    ans[x][y] = 0;
                }
            }
        }
    }
    int cnt = 0;
    FOR(i,1,n) {
        FOR(j,1,m) {
            if (ans[i][j] == -1) {
                label[i][j] = ++cnt;
            }
            cerr << label[i][j] << " ";
        }
        cerr << "\n";
    }
    vector<vector<double>> A(MAXS, vector<double> (MAXS));
    vector<double> b(MAXS);

    int row = 0;
    FOR(i,1,n) {
        FOR(j,1,m) {
            if (a[i][j] == 0 || a[i][j] == 4) continue;
            int tmp = 0;
            cerr << i << " " << j << ":\n";
            FOR(t,0,3) {
                int x = dx[t] + i;
                int y = dy[t] + j;
                if (!valid(x, y)) continue;
                if (!label[x][y]) {
                    tmp+= ans[x][y];
                }
                else {
                    A[row][label[x][y]-1] = 1;
                    cerr << label[x][y] - 1 << " "; 
                }
            }
            idx[i][j] = row;
            A[row][cnt] = a[i][j] - tmp;
            cerr << " = " << a[i][j] - tmp << endl;
            row++;
        }
    }
    gauss(A, b, row, cnt-1);
    FOR(i,0,row-1) {
        FOR(j,0,cnt) {
            cerr << A[i][j] << " ";
        }
        cerr << endl;
    }
    FOR(i,0, row-1) cout << b[i] << " ";
    cout << endl << endl;
    FOR(x,1,n) {
        FOR(y,1,m) {
            if (label[x][y]) {
                ans[x][y] = b[label[x][y]-1];
            }
            cout << ans[x][y] << " ";
        }
        cout << "\n";
    }
    return 0;
}