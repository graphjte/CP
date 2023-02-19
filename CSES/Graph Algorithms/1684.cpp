#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

vector<char> res;
vector<int> E;
vector<int> g[MAX], gr[MAX];

int n, m, vs[MAX], Id[MAX], cnt;

void DFS1(int u){
	vs[u] = true;
	for(int v: g[u]) if (!vs[v]) DFS1(v);
	E.push_back(u);
}

void DFS(int u, int id){
	Id[u] = id;
	for(int v: gr[u]) if (!Id[v]) DFS(v,id);
}

void Solve(){
	for(int i=1; i<=2*m; i++) if (!vs[i]) DFS1(i);
	reverse(E.begin(), E.end());
	for(int x: E){
		if (!Id[x]) DFS(x, ++cnt);
	}
	for(int i=1; i<=m; i++){
		if (Id[i] == Id[i+m]) {
			cout << "IMPOSSIBLE";
			return;
		}
		if (Id[i] < Id[i+m]){
			res.push_back('+');
		}
		else res.push_back('-');
	}
	for(char x: res) cout << x << " ";
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		char t1, t2; int u, v;
		cin >> t1 >> u >> t2 >> v;
		int nu = u, nv = v;
		if (t1 == '+') u+=m;
		else nu+=m;
		if (t2 == '+') v+=m;
		else nv+=m;
		g[nu].push_back(v);
		g[nv].push_back(u);
		//Dao cac canh nguoc lai de khoa cac chu trinh
		gr[u].push_back(nv);
		gr[v].push_back(nu);
	}
	Solve();

	return 0;
}