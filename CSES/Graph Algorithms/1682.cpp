#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int Num[MAX], Low[MAX], cnt, nComp, r[MAX], vs[MAX], n, m;
vector<int> g[MAX];
stack<int> st;

void DFS(int u){
	st.push(u);
	Num[u] = Low[u] = ++cnt;
	for(int v: g[u]){
		if (vs[v]) continue;
		if (Num[v]) Low[u] = min(Low[u], Num[v]);
		else {
			DFS(v);
			Low[u] = min(Low[u], Low[v]);
		}
	}
	if (Low[u] == Num[u]){
		nComp++; r[nComp] = u;
		int v;
		do{
			v = st.top(); st.pop();
			vs[v] = true;
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
	if (nComp == 1) cout << "YES";
	else{
		cout << "NO\n";
		cout << r[1] << " " << r[2];
	}
	return 0;
}