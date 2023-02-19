#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, m, Pre[MAX], vs[MAX];
vector<int> d;
vector<int> g[MAX];

void Trace(int n){
	if (!n) return;
	Trace(Pre[n]);
	d.push_back(n);
}

void BFS(){
	queue<int> q;
	q.push(1);
	vs[1] = true;

	while (!q.empty()){
		int u = q.front(); q.pop();
		if (u==n) break;
		for(int v: g[u]){
			if (!vs[v]) {
				vs[v] = true;
				q.push(v);
				Pre[v] = u;
			}
		}
	}
	if (!vs[n]) {
		cout << "IMPOSSIBLE";
		return;
	}
	Trace(n);
	cout << d.size()<< "\n";
	for(int x: d) cout << x << " ";
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
	BFS();
	return 0;
}