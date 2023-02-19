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
        int n, w, h;
        cin >> n >> w >> h;
        vector<ll> a(n+ 1), b(n+1);
        FOR(i,1,n) {
            cin >> a[i];
        }
        FOR(i,1,n) {
            cin >> b[i];
        }
        ll L = -1e12, R = 1e12; 
        FOR(i,1,n) {
            L = max(L, a[i] - w + h - b[i]);
            R = min(R, a[i] + w - h - b[i]);
        }
        cerr << L << " " << R << endl;
        if (R>=L) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}