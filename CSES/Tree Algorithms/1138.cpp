#include <bits/stdc++.h>
#define int long long
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

int n, m, a[MAX], d[MAX], c[MAX], pos[MAX], B[MAX];
vector<int> g[MAX];
vector<int> E;

void DFS(int u, int par){
	c[u] = 1;
	E.push_back(u);
	pos[u] = E.size()-1;
	d[u] = d[par] + a[u];
	for(int v: g[u]){
		if (v==par) continue;
		DFS(v, u);
		c[u]+= c[v];
	}
}

void Update(int x, int k){
	for(; x<=n; x+=x&-x) B[x]+= k;
}

int Query(int x){
	int ret = 0;
	for(; x>0; x-=x&-x) ret+= B[x];
	return ret;
}

int32_t main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> m;
	E.push_back(0);
	FOR(i,1,n){
		cin >> a[i];
	}
	FOR(i,1,n-1){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	DFS(1,1);

	FOR(i,1,n){
		Update(i, d[E[i]] - d[E[i-1]]);
	}
	FOR(i,1,m){
		int Type,u ,v;
		cin >> Type;
		if (Type==1){
			cin >> u >> v;
			Update(pos[u],v - a[u]);
			Update(pos[u]+c[u],a[u]-v);
			a[u] = v;
		}
		else{
			cin >> u;
			cout << Query(pos[u]) << "\n";
		}
	}

	return 0;
}