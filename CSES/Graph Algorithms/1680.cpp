#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int tr[MAX], vs[MAX], n, m, f[MAX];
vector<int> d;
vector<int> g[MAX];


void Trace(int u){
	if (!u) return;
	Trace(tr[u]);
	cout << u << " ";
}

void DFS(int u){
	vs[u] = true;
	for(int v: g[u]) 
		if(!vs[v]) DFS(v);
	d.push_back(u);
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
	reverse(d.begin(), d.end());

	for(int i=2; i<=n; i++) f[i] = -9999999;
	f[1] = 0;

	for(int x: d){
		for(int y: g[x]){
			if (f[x] + 1 > f[y]){
				f[y] = 1 + f[x];
				tr[y] = x;
			}
		}
	}
	if (f[n] < 0) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	cout << f[n] + 1 << "\n";
	Trace(n);
	return 0;
}