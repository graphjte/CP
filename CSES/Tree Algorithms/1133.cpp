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

ll c[MAX], d[2][MAX], n;
vector<int> g[MAX];

void DFS(int u, int par){
	c[u] = 1;
	for(int v: g[u]){
		if (v==par) continue;
		DFS(v, u);
		c[u]+= c[v];
		d[0][u]+= d[0][v] + c[v];
	}

}

void DFS2(int u, int par){
	for(int v: g[u]){
		if (v==par) continue;
		d[0][v] = d[0][u] - c[v] + (n-c[v]);
		DFS2(v, u);
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
	FOR(i,1,n-1){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	DFS(1,0);
	DFS2(1,0);
	FOR(i,1,n) cout << d[0][i] << " ";
	return 0;
}