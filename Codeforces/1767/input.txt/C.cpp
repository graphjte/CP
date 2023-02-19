#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 2e2+6;
const int MOD = 998244353;

int a[MAX][MAX];

long long Calc(int l, int r) {
    if (l==r) {
        if (a[l]==2) {
            return 0;
        }
        else {
            return 1;
        }
    }
    if (a[l][r] == 1) {
        return 2;
    }
    if (a[l][r]==2) {
        if (a[l][r] == 2 && a[l][r-1] == 1) return Calc(l,r-1);
        if (a[l][r] == 2 && a[l+1][r] == 1) {
            return Calc(l+1,r);
        }
        else return Calc(l+1, r-1);
    }
    else {
        
    }
}

int32_t main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    
    int T = 1;
    // cin >> T;
    while (T--) {
        int n;
        cin >> n;
        FOR(i,1,n) {
            FOR(j,i,n) {
                cin >> a[i][j];
            }
        }
        cout << Calc(1,n) << "\n";
    }
    return 0;
} 