#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ii pair<ll, int>
using namespace std;

const int MAX = 2e5+6;
const ll MX = 1e15;
const int MOD = 1e9+7;

int n, m, c[MAX], Mi[MAX], Ma[MAX];
ll d[MAX];

vector<ii> g[MAX];

void Dijkstra(){
	for(int i=2; i<=n; i++){
		d[i] = MX;
		c[i] = 0;
		Mi[i] = INT_MAX;
		Ma[i] = 0;
	}
	d[1] =0; c[1] =1; Mi[1] = Ma[1] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0,1));

	while (!pq.empty()){
		int u  =pq.top().se;
		ll du = pq.top().fi;
		pq.pop();
		if (du != d[u]) continue;
		// cout << u << " " << d[u] << "\n";
		for(ii t: g[u]){
			int v = t.se;
			ll uv = t.fi;
			if (du + uv == d[v]){
				// cout << u << " " << v << "\n";
				c[v]+=c[u];
				c[v]%= MOD;
				Mi[v] = min(Mi[u]+1, Mi[v]);
				Ma[v] = max(Ma[u]+1, Ma[v]);
			}
			if (du + uv < d[v]){
				d[v] = du + uv;
				c[v] = c[u];
				Mi[v] = Mi[u] + 1;
				Ma[v] = Ma[u] + 1;
				pq.push(ii(d[v],v));
			}
		}
	}
	cout << d[n] << " " << c[n] << " " << Mi[n] << " " << Ma[n];
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
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back(ii(w,v));
	}
	Dijkstra();
	return 0;
}