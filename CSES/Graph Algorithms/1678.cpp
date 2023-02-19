#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, m, color[MAX], Pre[MAX];
stack<int> st;
vector<int> g[MAX];

void printCycle(int v){
	st.push(v);
	int u = v;
	do{
		u = Pre[u];
		st.push(u);
	}while (v!=u);
	cout << st.size() << "\n";
	while (!st.empty()){
		cout << st.top() <<" "; st.pop();
	}
}

void DFS(int u){
	color[u] = 1;
	for(int v: g[u]){
		if (color[v]==2) continue;
		else if (color[v]==1){
			Pre[v] = u;
			printCycle(v);
			exit(0);
		}
		else {
			Pre[v] = u;
			DFS(v);
		}
	}
	color[u] = 2;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	for(int i=1; i<=n; i++){
		if (!color[i]) DFS(i);
	}
	cout << "IMPOSSIBLE";
	return 0;
}