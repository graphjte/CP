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
const int M = 21;

int In[MAX], Out[MAX], p[MAX][25], cnt, f[MAX], n, m;
vector<int> g[MAX];

void DFS(int u, int par){
	In[u] = ++cnt;
	p[u][0] = par;
	FOR(i,1,M) p[u][i] = p[p[u][i-1]][i-1];
	for(int v: g[u]){
		if (v==par) continue;
		DFS(v, u);
	}
	Out[u] = ++cnt;
}

bool Ancestor(int u, int v){
	return In[u]<=In[v] && Out[u]>=Out[v];
}

int LCA(int u, int v){
	if (Ancestor(u,v)) return u;
	if (Ancestor(v,u)) return v;
	FORD(i,M,0){
		if (!Ancestor(p[u][i],v) && p[u][i]>0) u = p[u][i];
	}
	return p[u][0];
}

void DFS2(int u, int par){
	for(int v: g[u]){
		if (v==par) continue;
		DFS2(v, u);
		f[u]+= f[v];
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> m;
	FOR(i,1,n-1){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	DFS(1,0);
	FOR(i,1,m){
		int u, v;
		cin >> u >> v;
		f[u]++; f[v]++; f[LCA(u, v)]--; f[p[LCA(u,v)][0]]--;
	}
	DFS2(1,0);
	FOR(i,1,n) cout << f[i] << " ";
	return 0;
}