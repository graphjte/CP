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

int a[3][3];
bool Check() {
    return a[0][0] < a[0][1] && a[1][0] < a[1][1] 
    && a[0][0] < a[1][0] && a[0][1] < a[1][1] ;
}

void Rotate() {
    int tmp = a[0][0];
    a[0][0] = a[1][0];
    a[1][0] = a[1][1];
    a[1][1] = a[0][1];
    a[0][1] = tmp;
}
int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    
    int T = 1;
    cin >> T;
    while (T--) {
        FOR(i,0,1) {
            FOR(j,0,1) cin >> a[i][j];
        }
        FOR(i,0,4) if (!Check()) Rotate();
        if (!Check()) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}