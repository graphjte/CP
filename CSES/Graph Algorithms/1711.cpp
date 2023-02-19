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

const int MAX = 550+6;
const int MOD = 1e9+7;

int n, m, tr[MAX];
int c[MAX][MAX], f[MAX][MAX], maxFlow;
vector<vector<int> > tmp;

void BFS(int u){
	queue<int> q;
	q.push(u);
	while (!q.empty()){
		int u = q.front(); q.pop();
		FOR(v,1,n){
			if (!tr[v] && f[u][v] < c[u][v]) {
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

bool DFS(int u){
	if (u==n) return true;
	FOR(v,1,n){
		if (c[u][v]==1 && f[u][v] == c[u][v]){
			f[u][v]--;
			tr[v] = u;
			return DFS(v);
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> m;
	FOR(i,1,m){
		int u, v;
		cin >> u >> v;
		c[u][v] = 1;
	}
	while (findPath()) {
		pushFlow();
	}
	cout << maxFlow << "\n";
	while (DFS(1)){
		vector<int> res;
		for(int v = n; v>0; v=tr[v]){
			res.push_back(v);
		}
		cout << res.size() << "\n";
		reverse(all(res));
		for(int t: res) cout << t << " ";
		cout << "\n";
	}
	return 0;
}