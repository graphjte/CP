#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 555;
const ll MAXL = 1e13;

ll f[MAX][MAX];
int n, m, q;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> m >> q;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			f[i][j] = MAXL;
		}
		f[i][i] = 0;
	}
	for(int i=1; i<=m; i++){
		int u,v;
		ll w;
		cin >> u >> v >> w;
		f[u][v] = f[v][u] = min(w, f[u][v]);
	}
	//Floyd
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++){
				if (f[i][k] + f[k][j] < f[i][j]) {
					f[i][j] = f[j][i] = f[i][k] + f[k][j];
				}
			}
	}

	//Queries
	for(int i=1; i<=q ;i++){
		int u,v;
		cin >> u >> v;
		if (f[u][v] == MAXL) cout << -1 << "\n";
		else cout << f[u][v] << "\n";
	}
	return 0;
}