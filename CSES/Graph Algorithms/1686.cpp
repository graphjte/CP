#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

ll f[MAX], res, Sz[MAX], a[MAX];
int Low[MAX], Num[MAX], nComp, n, m, cnt, vs[MAX], Id[MAX];
vector<int> adj[MAX], g[MAX];
stack<int> st;
vector<int> d;

void DFS2(int u){
	vs[u] = true;
	for(int v: adj[u]) if (!vs[v]) DFS2(v);
	d.push_back(u);
}

void DFS(int u){
	st.push(u);
	Low[u] = Num[u] = ++cnt;
	for(int v: g[u]){
		if (Id[v]) continue;
		if (Num[v]) Low[u] = min(Low[u], Num[v]);
		else{
			DFS(v);
			Low[u] = min(Low[u], Low[v]);
		}
	}
	if (Low[u] == Num[u]){
		int v; nComp++; 
		do{
			v = st.top(); st.pop();
			Id[v] = nComp; Sz[nComp]+= a[v];
		} while (v!=u);
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
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	for(int i=1; i<=n; i++) if (!Num[i]) DFS(i);
	for(int i=1; i<=n; i++){
		for(int j: g[i]){
			if (Id[i]!=Id[j]) adj[Id[i]].push_back(Id[j]);
		}
	}
	for(int i=1; i<=nComp; i++) if (!vs[i]) DFS2(i);
	reverse(d.begin(), d.end());

	for(int i=1; i<=nComp; i++) f[i] = Sz[i];

	for(int x: d) {
		for(int y: adj[x]){ 
			f[y] = max(f[y], Sz[y] + f[x]);
		}
		res = max(res, f[x]);
	}
	cout << res;
	return 0;
}