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

int d[3][MAX], f[MAX], n;
vector<int> g[MAX];

void DFS(int u, int par){
	d[2][u] = d[2][par]+1;
	for(int v: g[u]){
		if (v==par) continue;
		DFS(v, u);
		if (d[0][v]+1>=d[0][u]){
			d[1][u] = d[0][u];
			d[0][u] = d[0][v]+1;
		} 
		else{
			d[1][u] = max(d[1][u], d[0][v] + 1);
		}
	}
}

void DFS2(int u, int par){
	for(int v: g[u]){
		if (v!=par) {
			d[2][v] = d[2][u]+1;
			if (d[0][u] == d[0][v]+1){
				d[2][v] = max(d[2][v], d[1][u]+1);
			}
			else d[2][v] = max(d[2][v], d[0][u]+1);
			DFS2(v, u);
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

	cin >> n;
	d[2][0] = -1;
	FOR(i,1,n-1){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	DFS(1,0);
	DFS2(1,0);
	FOR(u,1,n) cout << max(d[2][u], d[0][u]) << " ";
	return 0;
}