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
    
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n==3) {
            cout << "NO\n";
        }
        else if (n%2==0) {
            cout << "YES\n";
            FOR(i,1,n) {
                if (i&1) cout << -1 << " ";
                else cout << 1 << " ";
            }
            cout << "\n";
        }
        else {
            cout << "YES\n";
            FOR(i,1,n) {
                if (i&1) {
                    cout << (1-n/2) << " ";
                }
                else cout << (n/2) << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}