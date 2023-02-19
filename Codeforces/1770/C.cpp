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
        int n;
        cin >> n;
        vector<int> a(n+1);
        bool ok = true;
        map<int, int> M;
        FOR(i,1,n) {
            cin >> a[i];
            if (M[a[i]]) ok= false;
            M[a[i]]++;
        }
        FOR(i,2,n) {
            bool loc = false;
            vector<int> cnt(i);
            FOR(j,1,n) {
                cnt[a[j]%i]++;
            }
            FOR(j,0,i-1) {
                if (cnt[j] < 2)  loc = true;
            }
            if (!loc) ok = 0;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}