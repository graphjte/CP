//https://codeforces.com/contest/1770/problem/E
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

struct centroidDecomposition {
    vector<set<int> > g;
    vector<map<int, int> > dist;
    vector<int> sz, p, ans;
    int n;

    centroidDecomposition(int n) : n(n), sz(n+1), ans(n+1, MOD), p(n+1) {//change this line
        dist.resize(n+1);
        g.resize(n+1);
    }

    void addEdge(int &u, int &v) {
        g[u].insert(v);
        g[v].insert(u);
    }

    int DFS(int u, int par) {
        sz[u] = 1;
        for(auto &v: g[u]) {
            if (v==par) continue;
            sz[u] += DFS(v, u);
        }
        return sz[u];
    }

    int centroid(int u, int par, int n) {
        for(auto &v: g[u]) {
            if (v==par) continue;
            if (sz[v] > n/2) return centroid(v, u, n);
        }
        return u;
    }

    void buildDistances(int u, int p, int c, int d) {
        dist[c][u] = d;
        for(auto &v: g[u]) {
            if (v==p) continue;
            buildDistances(v, u, c, d+1);
        }
    }

    void build(int u, int par) {
        int n = DFS(u, par);
        int c = centroid(u, par, n);
        p[c] = par;
        buildDistances(c, par, c, 0);

        vector<int> tmp(g[c].begin(), g[c].end());
        for(auto &v: tmp) {
            g[v].erase(c);
            g[c].erase(v);
            build(v, c);
        }
    }

    void modify(int u) {
        for(int v = u; v!=0; v = p[v]) ans[v] = min(ans[v], dist[v][u]);
    }
    
    int query(int u) {
        int curAns = INT_MAX;
        for(int v = u; v!=0; v = p[v]) curAns = min(curAns, ans[v] + dist[v][u]);
        // v is an ancestor of u in the centroid tree
        return curAns;
    }
};

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int T = 1;
    while (T--) {
        int n, q;
        cin >> n >> q;
        centroidDecomposition cd(n);
        FOR(i,1,n-1) {
            int u, v;
            cin >> u >> v;
            cd.addEdge(u, v);
        }
        cd.build(1, 0);
        cd.modify(1);
        while (q--) {
            int Type, u;
            cin >> Type >> u;
            if (Type==1) {
                cd.modify(u);
            }
            else {
                cout << cd.query(u) << "\n";
            }
        }

    } 
    return 0;
}