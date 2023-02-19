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

const int MAX = 2e5+6;
const int MOD = 1e9+7;

int32_t main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int T = 1;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        ll sum = 0;
        vector<int> c(m+3), a(n+3);
        multiset<int> S;
        FOR(i,1,n) {
            cin >> a[i];
            S.insert(a[i]);
            sum+= a[i];
        }
        FOR(i,1,m) {
            cin >> c[i];
            sum-= *S.begin();
            sum+= c[i];
            S.erase(S.begin());
            S.insert(c[i]);
        }
        cout << sum << "\n";
    }
    return 0;
}