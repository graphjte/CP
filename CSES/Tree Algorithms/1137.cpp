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

ll B[MAX], d[MAX], c[MAX], pos[MAX], cnt, n, m, a[MAX];
vector<int> g[MAX];

ll Query(int x){
	ll ret = 0;
	for(; x>0; x-=x&-x) ret+= B[x];
	return ret;
}

void Update(int x, int k){
	for(; x<=n; x+=x&-x) B[x]+=k;
}

void DFS(int u, int par){
	d[++cnt] = u;
	c[u] = 1;
	pos[u] = cnt;
	for(int v: g[u]){
		if (v!=par) {
			DFS(v, u);
			c[u]+= c[v];
		}
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
	FOR(i,1,n) cin >> a[i];
	FOR(i,1,n-1){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	DFS(1,0);
	FOR(i,1,n){
		Update(pos[i], a[i]);
	}
	FOR(i,1,m){
		int Type, u, v;
		cin >> Type;
		if (Type==1){
			cin >> u >> v;
			Update(pos[u], v - a[u]);
			a[u] = v;
		}
		else{
			cin >> u;
			cout << Query(pos[u]+c[u]-1) - Query(pos[u]-1) << "\n";
		}
	}

	return 0;
}