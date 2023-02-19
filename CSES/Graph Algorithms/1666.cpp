#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int vs[MAX], n, m, c[MAX], cnt;

vector<int> g[MAX];

void DFS(int u){
	vs[u] = true;
	for(int v: g[u]){
		if (!vs[v]) DFS(v);
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
		if (!vs[i]) {
			DFS(i);
			c[++cnt] = i;
		}
	}
	cout << cnt-1 << "\n";
	for(int i=2; i<=cnt; i++){
		cout << c[i-1] << " " << c[i] << "\n";
	}
	return 0;
}