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
const int MOD = 998244353;

int n, n_edges, n_vertices, n_self_loop;
vector<int> a, b, vs;
vector< vector<int> > g;

void DFS(int u) {
    n_vertices++;
    vs[u] = true;
    for(auto &v: g[u]) {
        if (!vs[v]) {
            DFS(v);
        }
        else {
            n_edges++;
            if (v==u) n_self_loop++;
        }
    }
}

void Solve() {
    cin >> n;
    a.assign(n+1, 0), b.assign(n+1, 0);
    vs.assign(n+1, 0);
    g.assign(n+1, vector<int> (0));
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) {
        cin >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    ll ans = 1;
    FOR(i,1,n) {
        if (!vs[i]) {
            n_edges = 0;
            n_vertices = 0;
            n_self_loop = 0;
            DFS(i);
            if (n_self_loop) ans*= 1ll *n, ans %= MOD;
            else ans*= 2, ans %= MOD;
            if (n_edges !=1 + n_vertices) {
                ans = 0;
            }
        }
    }
    cout << ans << "\n";
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int T = 1;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
} 