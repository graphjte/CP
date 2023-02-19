#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, m, vs[MAX];
vector<int> d;
vector<int> g[MAX];
bool cyclFound;

void DFS(int u){
	vs[u] = 1;
	for(int v: g[u]){
		if (!vs[v]) DFS(v); 
		if (vs[v]==1) cyclFound = true;
	}
	d.push_back(u);
	vs[u] = 2;
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
	}
	for(int i=1; i<=n; i++) if (!vs[i]) DFS(i);
	if (cyclFound) {
		cout << "IMPOSSIBLE";
	}
	else{
		reverse(d.begin(), d.end());
		for(int x: d) cout << x << " ";
	}
	return 0;
}