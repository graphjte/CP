#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, m, In[MAX], vs[MAX];
vector<ii> g[MAX];
vector<int> E;

void DFS(int u){
	// cout << u << "\n";
	while (g[u].size()){
		int v = g[u].back().fi;
		int id= g[u].back().se;
		g[u].pop_back();
		if(vs[id]) continue;
		vs[id] = true;
		DFS(v);
	} 
	E.push_back(u);
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
		g[u].push_back(ii(v,i));
		g[v].push_back(ii(u,i));
		In[v]++; In[u]++;
	}
	DFS(1);
	if (E.size() != m+1){
		cout << "IMPOSSIBLE";
		return 0;
	}
	for(int i=1; i<=n; i++){
		if (In[i]%2!=0) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	for(int x: E) cout << x << " ";
	return 0;
}