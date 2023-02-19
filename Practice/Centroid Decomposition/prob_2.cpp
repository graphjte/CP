//https://oj.vnoi.info/problem/lqdrace
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
    vector<set<ii> > g;
    vector<int> sz, p;
    vector<int> dist;
    vector<ii> tmp;
    int n, k, ans;

    centroidDecomposition(int n, int k) : k(k), n(n), sz(n+1), p(n+1) {//change this line
        g.resize(n+1);
        dist.resize(k+10, MOD);
        ans = MOD;
    }

    void addEdge(int &u, int &v, int &w) {
        g[u].insert({v, w});
        g[v].insert({u, w});
    }

    int DFS(int u, int par) {
        sz[u] = 1;
        for(auto [v, w]: g[u]) {
            if (v == par) continue;
            sz[u] += DFS(v, u);
        }
        return sz[u];
    }

    int centroid(int u, int par, int n) {
        for(auto [v, w]: g[u]) {
            if (v == par) continue;
            if (sz[v] > n/2) return centroid(v, u, n);
        }
        return u;
    }

    void DFS2(int u, int par, int len, int depth) {
        if (len <= k) ans = min(ans, dist[k - len] + depth);
        tmp.push_back({len, depth});
        for(auto [v, w]: g[u]) {
            if (v==par) continue;
            DFS2(v, u, len + w, depth + 1);
        }
    }

    void findAnswer(int u) {
        vector<int> to_reverse;
        for(auto [v, w]: g[u]) {
            tmp.clear();
            DFS2(v, u, w, 1);
            for(auto [len, depth]: tmp) {
                if (len <= k) dist[len] = min(dist[len], depth);
                to_reverse.push_back(len);
            }
        }
        for (auto &v: to_reverse) {
            if (v <= k) dist[v] = MOD;
        }
    }

    int solve(int u, int par) {
        int n = DFS(u, par);
        int c = centroid(u, par, n);
        p[c] = par;
        dist[0] = 0;
        findAnswer(c); //find the edge that goes through vertex c and has the length of k

        vector<ii> tmp(g[c].begin(), g[c].end());
        for(auto [v, w]: tmp) {
            //there is no path go through vertex c, thus we can erase c and find the answer in each children node
            g[v].erase(ii(c,w));
            g[c].erase(ii(v,w));
            ans = min(ans, solve(v, c));
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int n, k;
    cin >> n >> k;
    centroidDecomposition cd(n, k);
    FOR(i,1,n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        u++; v++;
        cd.addEdge(u, v, w);
    }
    cd.solve(1, 0);
    if (cd.ans == MOD) cout << -1;
    else cout << cd.ans;
    return 0;
}
