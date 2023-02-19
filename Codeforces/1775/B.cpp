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
        vector<vector<int> > a(n+1);
        map<int, int> b;
        FOR(i,1,n) {
            int s;
            cin >> s;
            a[i].resize(s+1);
            FOR(j,1,s) cin >> a[i][j], b[a[i][j]]++;
        }
        bool ok = false;
        FOR(i,1,n) {
            bool flag = 0;
            FOR(j,1, a[i].size()-1) 
            if (b[a[i][j]] == 1) flag = 1;
            if (!flag) ok = true;
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}