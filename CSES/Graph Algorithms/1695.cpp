#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define ll long long
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 555+6;
const int MOD = 1e9+7;

int n, m, tr[MAX];
int c[MAX][MAX], f[MAX][MAX], maxFlow;

void BFS(int u){
	queue<int> q;
	q.push(u);
	while (!q.empty()){
		int u = q.front(); q.pop();
		if (u==n) return;
		FOR(v, 1, n){
			if (!tr[v] && f[u][v] < c[u][v]){
				// cout << f[u][v] << " " << c[u][v] << "\n";
				tr[v] = u;
				q.push(v);
			}
		}
	}
}

bool findPath(){
	fill(tr+1, tr+n+1, 0);
	tr[1] = -1;
	BFS(1);
	return tr[n];
}

void pushFlow(){
	int v = n;
	while (v!=1){
		int u = tr[v];
		f[u][v]++;
		f[v][u]--;
		v = u;
	}
	maxFlow++;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> m;
	for(int i=1; i<=m; i++){
		int u, v;
		cin >> u >> v;
		c[u][v] = c[v][u] = 1;
	}
	while (findPath()) pushFlow();
	memset(tr, 0, sizeof tr); tr[1] = -1;
	BFS(1);
	cout << maxFlow << "\n";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if (j!=i && tr[i] && !tr[j] && c[i][j]) cout << i << " " << j << "\n";
		}
	}
	return 0;
}