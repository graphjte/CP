#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, m, vs[MAX], c[MAX], bad;
vector<int> g[MAX];

void DFS(int u){
	vs[u] = true; 
	for(int v: g[u]){
		if (!vs[v]){
			c[v] = 1 - c[u];
			DFS(v);
		}
		else if (c[v] == c[u]) bad = true;
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
		if (!vs[i]) DFS(i);
	}
	if (bad) cout << "IMPOSSIBLE";
	else{
		for(int i=1; i<=n; i++) cout << c[i] + 1 << " ";
	}
	return 0;
}