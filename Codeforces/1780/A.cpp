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
        vector<int> a(n+1), odds, evens;
        FOR(i,1,n) cin >> a[i];
        FOR(i,1,n) if (a[i]&1) {
            odds.push_back(i);
        }
        else evens.push_back(i);
        if (odds.size() >=3) {
            cout << "YES\n";
            FOR(i,0,2) cout << odds[i] << " ";
            cout << "\n";
            continue;
        }
        else if (odds.size() >=1 && evens.size() >=2) {
            cout << "YES\n";
            FOR(i,0,1) cout << evens[i] << " ";
            cout << odds[0];
            cout << "\n";
            continue;
        }
        cout << 
        "NO\n";
    } 
    return 0;
}