#include <bits/stdc++.h>
#define ii pair<ll, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

ll d[MAX];
int n, m;
vector<ii> g[MAX];

void Dijkstra(){
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0,1));
	fill(d+2, d+n+1, 1e14);

	while (!pq.empty()){
		int u = pq.top().se;
		ll du = pq.top().fi;
		pq.pop();
		if (du > d[u]) continue;

		for(ii t: g[u]){
			int v = t.se;
			ll uv = t.fi;
			if (du + uv < d[v]){
				d[v] = du + uv;
				pq.push(ii(d[v],v));
			}
		}
	}
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
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(ii(w,v));
	}
	Dijkstra();
	for(int i=1; i<=n; i++) cout << d[i] << " ";
	return 0;
}