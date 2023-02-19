#include <bits/stdc++.h>
#define ii pair<ll, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2507;
const ll MAXL = 1e16;

ll d[MAX];
int n, vs[MAX], m, cnt[MAX];
vector<ii> dd[MAX][2];
vector<ii> g[MAX];

void DFS(int u, int id){
	vs[u] = true; cnt[u]++;
	for(ii t: dd[u][id]){
		int v = t.se;
		if (!vs[v]) DFS(v,id);
	}
}

void Bellman_Ford(){
	for(int i=2; i<=n; i++) d[i] = MAXL;

	bool updated;
	for(int k=1; k<=n; k++){
		updated = false;
		for(int i=1; i<=n; i++){
			for(ii t: g[i]){
				int j = t.se;
				ll ij = t.fi;
				if (d[i] + ij < d[j]){
					d[j] = d[i] + ij;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
	if (updated) cout << -1;
	else cout << -d[n];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> m;
	for(int i=1; i<=m; i++){
		int u,v;
		ll w;
		cin >> u >> v >> w;
		dd[u][0].push_back(ii(-w,v));
		dd[v][1].push_back(ii(-w,u));
	}
	DFS(1,0);
	memset(vs,0,sizeof vs);
	DFS(n,1);

	for(int i=1; i<=n; i++){
		for(ii t: dd[i][0]){
			int j = t.se;
			if (cnt[j] == 2){
				g[i].push_back(t);
			}
		}
	}
	Bellman_Ford();
	return 0;
}