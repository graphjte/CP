#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; i++)
#define FORD(i,r,l) for(int i=r; i>=l; i--)
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

struct solution{
    vector< vector<int> > f;
    vector<ii> a;
    vector<vector<int> > g;
    vector<int> vs;

    bool ke(int i, int j){
        return abs(a[i].fi - a[j].fi) + abs(a[i].se - a[j].se) == 1;
    }

    void DFS(int u, int root, int color){
        vs[u] = true;
        f[root][color]++;
        for(auto &v: g[u]){
            if (!vs[v]){
                DFS(v, root, color);
            }
        }
    }

    void solve(int n){
        a.resize(n+3);
        f.resize(n+3, vector<int> (3));
        vs.resize(n+3);
        g.resize(n+3);

        FOR(i,1,n){
            cin >> a[i].first >> a[i].second;
        }
        FOR(i,1,n){
            FOR(j,i+1,n){
                if (!ke(i,j)){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int res = 0;
        FOR(i,1,n){
            if (!vs[i]){
                DFS(i, i, 0);
                res+= max(f[i][0], f[i][1]);
            }
        }
        cout << res << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen("input.txt","r"))
        freopen("input.txt","r", stdin);

    int n;
    while (cin >> n){
        solution t;
        t.solve(n);
    }
}
