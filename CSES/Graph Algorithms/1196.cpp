#include <bits/stdc++.h>
#define ii pair<ll, int>
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
const ll INF = 1e18;

int cnt[MAX], n, m, k;
ll d[MAX];
vector<ii> g[MAX];

void Dijkstra(){
	FOR(i,2,n) d[i] = INF;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0,1));

	while (!pq.empty()){
		ll du = pq.top().fi; int u = pq.top().se; pq.pop();
		cnt[u]++;
		if (cnt[u] > k) continue;
		if (u==n && cnt[u]<=k){
			cout << du << " ";
		}
		for(ii t: g[u]){
			int v = t.se; ll uv = t.fi;
			pq.push(ii(du + uv,v));
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

	cin >> n >> m >> k;
	FOR(i,1,m){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(ii(w,v));
	}
	Dijkstra();
	return 0;
}