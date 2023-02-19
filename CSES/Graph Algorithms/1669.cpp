#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, m, vs[MAX], Pre[MAX];
vector<int> g[MAX];
vector<int> d;

void DFS(int u, int par){
	vs[u] = true;
	for(int v: g[u]){
		if (v==par) continue;
		if (!vs[v]){
			Pre[v] = u;
			DFS(v, u);
		}
		else{
			d.push_back(v); d.push_back(u);
			int t = u;
			while (t!=v){
				t = Pre[t];
				d.push_back(t);
			}
			cout << d.size() << "\n";
			for(int x: d) cout << x << " ";
			exit(0);
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
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1; i<=n; i++){
		if (!vs[i]) DFS(i,i);
	}
	cout << "IMPOSSIBLE";
	return 0;
}