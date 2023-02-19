#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int Num[MAX], Low[MAX], cnt, nComp, Id[MAX], n, m;
vector<int> g[MAX];
stack<int> st;

void DFS(int u){
	Low[u] = Num[u] = ++cnt;
	st.push(u);
	for(int v: g[u]){
		if (Id[v]) continue;
		if (Num[v]) Low[u] = min(Low[u], Num[v]);
		else{
			DFS(v);
			Low[u] = min(Low[u], Low[v]);
		}
	}
	if (Low[u] == Num[u]){
		int v=0; nComp++;
		do{
			v = st.top(); st.pop();
			Id[v] = nComp;
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
	for(int i=1; i<=m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	for(int i=1; i<=n; i++) if (!Num[i]) DFS(i);

	cout << nComp << "\n";
	for(int i=1; i<=n; i++) cout << Id[i] << " ";
	return 0;
}