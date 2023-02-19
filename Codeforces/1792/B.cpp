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
        vector<int> x(5);
        FOR(i,1,4) cin >> x[i];
        if (!x[1]) {
            cout << 1 << "\n";
            continue;
        }
        int ans = x[1] + min(x[2], x[3]) * 2; 
        int tmp = min(x[2], x[3]);
        x[2]-=tmp, x[3] -=tmp;
        tmp = max({x[2], x[3]}) + x[4];
        ans+= min(x[1], tmp);
        if (x[1] < tmp) ans++;
        cout << ans << "\n";
    }
    return 0;
}