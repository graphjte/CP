#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define ll long long
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e9+7;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif
    
    int n, m, p1 = -1, p2 = -1;
    cin >> n >> m;
    vector<ii> a(n+3);
    FOR(i,1,n) {
        cin >> a[i].fi >> a[i].se;
        if (p1 == -1 || a[i].fi > a[p1].fi) p1 = i;
        if (p2 == -1 || a[i].se < a[p2].se) p2 = i;
    }
    if (p1 == p2 || (a[p2].se >= a[p1].fi )) cout << "NO";
    else cout << "YES\n" << p1 << " " << p2;
    return 0;
}