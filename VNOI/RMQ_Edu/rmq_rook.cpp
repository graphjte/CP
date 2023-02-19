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

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<int> row(n+3), col(m+3);
    FOR(i,1,k) {
        int x, y;
        cin >> x >> y;
        row[x] = 1;
        col[y] = 1;
    }
    FOR(x,1,n) row[x] += row[x-1];
    FOR(x,1,m) col[x] += col[x-1];
    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        bool ok = ((row[x2] - row[x1-1]) == x2-x1+1) &&
        ((col[y2] - col[y1-1]) == y2-y1+1);
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}