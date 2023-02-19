#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;
const int MOD  =1e9+7;

int n, m, f[MAX], vs[MAX];
vector<int> g[MAX];
vector<int> d;

void DFS(int u){
	vs[u] = true;
	for(int v: g[u]) if (!vs[v]) DFS(v);
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
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	for(int i=1; i<=n; i++) if (!vs[i]) DFS(i);
	reverse(d.begin(), d.end());

	f[1] = 1;
	for(int x: d){
		for(int y: g[x]) {
			f[y]+= f[x];
			f[y]%=MOD;
		}
	}
	cout << f[n];
	return 0;
}