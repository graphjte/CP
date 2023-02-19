#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 5e5+6;
const int MOD = 1e9+7;

int n, m, k;
vector<int> g[MAX], d1, dn;
ll val_1[MAX], val_n[MAX], s_val_1[MAX], s_val_n[MAX];
vector<ii> E;

void BFS(int st, vector<int> &d) {
    d[st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto &v: g[u]) {
            if (d[v]==-1) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> n >> m >> k;
    FOR(i,1,m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        E.push_back({u, v});
    }
    d1.resize(n+1, -1);
    dn.resize(n+1, -1);
    BFS(1, d1);
    BFS(n, dn);
    int minDis = d1[n];
    FOR(i,1,n) {
        val_1[d1[i]]++;
        val_n[dn[i]]++;
    }
    if (k > minDis) {
        cout << 0 << "\n";
        return 0;
    }
    else if (minDis==k) {
        ll res = 0;
        s_val_1[0] = val_1[0];
        s_val_n[0] = val_n[0];
        FOR(i,1,n) {
            s_val_1[i] = s_val_1[i-1] + val_1[i];
            s_val_n[i] = s_val_n[i-1] + val_n[i];
        }
        FOR(i,0,n) {
            if (k - i - 2 >= 0)
                res+= 1ll * val_1[i] * s_val_n[k -i -2];
        }
        for(auto &tmp: E) {
            int u = tmp.first, v = tmp.second;
            if (d1[u] + dn[v] < k-1) {
                res--;
            }
            if (d1[v] + dn[u] < k-1) {
                res--;
            }
        }
        cout << 1ll * (n-1)*n / 2 - m - res;
    }
    else {
        ll res = 0;
        FOR(i,0,k-1) {
            res+= 1ll * val_1[i] * val_n[k-i-1];
        }
        for(auto &tmp: E) {
            int u = tmp.first, v = tmp.second;
            if (d1[u] + dn[v] == k-1) {
                res--;
            }
            if (d1[v] + dn[u] == k-1) {
                res--;
            }
        }
        cout << res << "\n";
    }
    return 0;
}