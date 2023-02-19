#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAXN = 2e5+6;
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
        int cnt = 0, nTurn = 0, r = 0;
        vector<vector<int> > a(2, vector<int>(2) );
        FOR(i,1,n) {
            if (i > r) {
                cnt++;
                r = i + cnt - 1;
                nTurn++;
                // if (T > 2)cout << i << endl;
            }
            if (i&1) {
                if (nTurn % 4 == 1 || nTurn % 4== 0) {
                    a[0][1]++;
                }
                else {
                    a[0][0]++;
                }
            }
            else {
                if (nTurn % 4 == 1 || nTurn % 4== 0) {
                    a[1][1]++;
                }
                else {
                    a[1][0]++;
                }
            }
        }
        cout << a[0][1] + a[1][1] << " ";
        cout << a[0][0] + a[1][0] << "\n";
    }
    return 0;
}