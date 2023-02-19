#include <bits/stdc++.h>
#define ii pair<ll, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;
const ll MX = 1e15;

ll d[MAX][3];

int n, m;
vector<ii> g[MAX];

struct Data{
	ll price;
	int u;
	bool type;
	Data(ll _price, int _u, bool _type){
		price = _price; u = _u; type = _type;
	}
};

bool operator < (Data a, Data b){
	if (a.price == b.price) return a.type > b.type;
	return a.price > b.price;
}

void Dijkstra(){
	for(int i=1; i <=n; i++){
		for(int j=0; j<=1; j++) d[i][j] = MX;
	}
	d[1][0] = 0;
	priority_queue <Data> pq;
	pq.push(Data(0,1,0));

	while (!pq.empty()){
		int u = pq.top().u; bool Type = pq.top().type; 
		ll du = pq.top().price;
		// cout << u << " " << Type << " " << du << "\n";
		pq.pop();
		if (du != d[u][Type]) continue;

		for(ii t: g[u]){
			ll uv = t.fi;
			int v = t.se;
			if (du + uv < d[v][Type]){
				d[v][Type] = du + uv;
				pq.push(Data(d[v][Type],v,Type));
			}
			if (!Type && du + uv/2 < d[v][1]){
				d[v][1] = du + uv/2;
				pq.push(Data(d[v][1],v,1));
			}
		}
	}
	cout << d[n][1];
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