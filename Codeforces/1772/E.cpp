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
        vector<int> a(n+1);
        int p1, p2, pc = 0;
        p2 = p1 = 0;
        FOR(i,1,n) {
            cin >> a[i];
            // cout << a[i] << "\n";
            if (a[i]!=i && a[i]!=n-i+1) {pc++; continue;}
            if (a[i]!=i) p1++;
            if (a[i]!=n-i+1) p2++;
        }
        // cout << p1 << " " << p2 << " " << pc << "\n";
        if (p1 + pc <= p2) cout << "First\n";
        else if (p2 + pc < p1 ) cout << "Second\n";
        else cout << "Tie\n";
    }
    return 0;
}