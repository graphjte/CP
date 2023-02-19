#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2555;
const ll MX = 1e15;

ll d[MAX];
int n, Tr[MAX], m, Ok, L, dd[MAX];
vector<ii> g[MAX];

void Trace(int u){
	if (dd[u]==1) {L = u; cout << u << " "; return;}
	dd[u] = true;
	Trace(Tr[u]);
	if (Ok) return;
	if (u==L) Ok = true;
	cout << u << " ";
}

void Bellman_Ford(){
	for(int i=2; i<=n; i++){
		d[i] = MX;
	}
	int Updated;
	for(int k=1; k<=n; k++){
		Updated = 0;
		for(int u=1; u<=n; u++){
			for(ii t: g[u]){
				int v = t.se;
				ll uv = t.fi;
				if (d[u] + uv < d[v]){
					d[v] = d[u] + uv;
					Tr[v] = u;
					Updated = v;
				}
			}
		}
		if (!Updated) break;
	}
	if (Updated){
		cout << "YES" << "\n";
		Trace(Updated);
		// Hoac co the lui lai n lan, sau n lan chac chan no se o trong chu trinh
		// for(int i=1; i<n; i++) u=par[u];
	}
	else cout << "NO";
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
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back(ii(w,v));
	}
	Bellman_Ford();
	return 0;
}