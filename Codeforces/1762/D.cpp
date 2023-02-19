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
        // freopen("input.txt","r",stdin);
    }
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//64-bit number generator
    int T;
    cin >> T;
    while (T--) {
    int n;
    cin >> n;
    if (n==2) {
        cout  << "! " << 1 << " " << 2 << endl;
        int tmp;
        cin >> tmp;
        continue;
    }
    vector<ii> a(n+1);
    vector<int> f(n+3);
    FOR(i,1,n) {
        a[i].se = i;
        a[i].fi = rng() % MOD;
    }
    sort(a.begin() + 1, a.end());
    a.push_back(a[1]);
    a.push_back(a[2]);
    FOR(i,1,n) {
        int x;
        cout << "? " << a[i].se << " " << a[i+1].se << endl;
        cin >> x;
        f[a[i].se] = max(f[a[i].se], x);
        f[a[i+1].se] = max(f[a[i+1].se], x);
        cout << "? " << a[i].se << " " << a[i+2].se << endl;
        f[a[i].se] = max(f[a[i].se], x);
        f[a[i+2].se] = max(f[a[i+2].se], x);
        cin >> x;
    }
    int pos = 1, pos2 = n;
    FOR(i,1,n) {
        if (f[i] > f[pos]) pos = i;
    }
    FOR(i,1,n) {
        if (i==pos) continue;
        if (f[i] > f[pos]) pos = i;
    }
    cout << "! " << a[pos].se << " " << a[pos2].se << endl;
    int x;
    cin >> x;
    }

    return 0;
}