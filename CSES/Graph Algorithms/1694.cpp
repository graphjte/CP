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

long long c[MAX][MAX], f[MAX][MAX], maxFlow;
int n, m, tr[MAX];

void BFS(int st){
	queue<int> q;
	q.push(st);
	while (!q.empty()){
		int u = q.front(); q.pop();
		for(int v=1; v<=n; v++){
			if (!tr[v] && f[u][v] < c[u][v]) {
				tr[v] = u;
				q.push(v);
			}
		}
	}
}

bool findPath(){
	memset(tr, 0, sizeof tr);
	tr[1] = -1;
	BFS(1);
	return tr[n];
}

void pushFlow(){
	ll delta = LLONG_MAX;
	int v = n;
	while(v!=1){
		int u = tr[v];
		delta = min(delta, c[u][v] - f[u][v]);
		v = u;
 	}
 	v = n;
 	while (v!=1){
 		int u = tr[v];
 		f[u][v]+= delta;
 		f[v][u]-=delta;
 		v = u;
 	}
 	maxFlow+= delta;
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
		int u, v,w;
		cin >> u >> v >> w;
		c[u][v] += w;
	}
	while (findPath()) pushFlow();
	cout << maxFlow;
	return 0;
}