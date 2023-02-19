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

const int MAX = 2e5+6;
const int MOD = 1e9+7;
const int M = 30;

int n, p[MAX][M+1], q, In[MAX], Out[MAX], cnt;
vector<int> g[MAX];

void DFS(int u){
	In[u] = ++cnt;
	for(int v: g[u]){
		p[v][0] = u;
		FOR(i,1,M) p[v][i] = p[p[v][i-1]][i-1];
		DFS(v);
	}
	Out[u] = ++cnt;
}

bool isPar(int u, int v){
	if (In[u]<=In[v] && Out[u]>=Out[v]) return true;
	return false;
}

int LCA(int u, int v){
	if (isPar(u, v)) return u;
	if (isPar(v, u)) return v;
	for(int i=M; i>=0; i--){
		if (p[u][i]>0 && !isPar(p[u][i],v)) u = p[u][i];
	}
	return p[u][0];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> q;
	FOR(i,2,n){
		int tmp;
		cin >> tmp;
		g[tmp].push_back(i);
	}
	DFS(1);
	FOR(i,1,q){
		int u, v;
		cin >> u >> v;
		cout << LCA(u, v) << "\n";
	}
	// cout << p[4][0] << "\n";
	return 0;
}