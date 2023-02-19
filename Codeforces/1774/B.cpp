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
        int Mx = 0, k, m;
        cin >> n >> m >> k;
        int r = n%k;
        vector<int> a(m+1);
        FOR(i,1,m) {
            cin >> a[i];
            Mx = max(Mx, a[i]);
        }
        int cnt = 0;
        int tmp = n/k + (n%k > 0);
        FOR(i,1,m) {
            if (a[i] == n/k+1) cnt++;
        }
        if (cnt > r) {cout << "NO\n"; continue;}
        if (Mx > (tmp)) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}