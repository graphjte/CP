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
    
    
    int T;
    cin >> T;
    while (T--) {
        int cnt = 0;
        vector<ii> x(5);
        map<int, int> ct;
        FOR(i,1,3) {
            cin >> x[i].fi >> x[i].se;
        }
        FOR(i,1,3) {
            FOR(j,i+1,3) {
                if (x[i].fi==x[j].fi) cnt++;
                if (x[i].se==x[j].se) cnt++;
            }
        }
        if (cnt < 2) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
} 