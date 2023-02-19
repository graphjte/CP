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
        vector<int> Max(100, 0), Min(100, 1);
        cin >> n;
        vector<int> a(n+1);
        FOR(j,1,n) {
            cin >> a[j];
            for(int i=0; i < 25; i++) {
                if ((a[j]& (1 << i))) {
                    Max[i] = 1  ;
                }
                else Min[i] = 0;
            }
        }
        int res = 0;
        FOR(i,0,30) {
            if (Max[i] > Min[i]) res+= 1 << i;
        }
        cout << res << "\n";
    }
    return 0;
}