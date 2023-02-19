#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 1e6+6;
const int MOD = 1e9+7;

int A, B, d;
int n, res;
vector<int> g[MAX], a, b, dis, req;

void DFSA(int u, int par) {
    for(auto &v: g[u]) {
        if (v==par) continue;
        DFSA(v, u);
        if (req[v]) req[u] = true;
    }
}

void DFSB(int u, int par) {
    for(auto &v: g[u]) {
        if (v==par) continue;
        DFSB(v, u);
        dis[u] = max(dis[u], dis[v] + 1);
    }
}

void DFSC(int u, int par) {
    if (dis[u]>=d) req[u] = true;
    for(auto &v: g[u]) {
        if (v==par) continue;
        DFSC(v, u);
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> n >> d;
    req.resize(n+1);
    dis.resize(n+1, 0);

    FOR(i,1,n-1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> A;
    FOR(j,0, A-1) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        req[tmp] = true;
    }

    DFSA(1,1);
    fill(dis.begin(), dis.end(), -MOD);

    cin >> B;
    FOR(j,0, B-1) {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
        dis[tmp] = 0;
    }
    DFSB(1,1);
    DFSC(1,1);
    FOR(i,1,n) if (req[i]) res+= 2;
    res-=2;

    fill(req.begin(), req.end(), 0);
    FOR(j,0, B-1) {
        req[b[j]] = true;
    }

    DFSA(1,1);
    fill(dis.begin(), dis.end(), -MOD);
    for(auto &v: a) dis[v] = 0;

    DFSB(1,1);
    DFSC(1,1);
    FOR(i,1,n) if (req[i]) res+= 2;
    cout << res-2;
    return 0;
}