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

int n, m, k, vs[MAX], cnt, matchX[MAX], res;
vector<int> g[MAX];

bool DFS(int u){
	if (vs[u] == cnt) return false;
	vs[u] = cnt;
	for(int v: g[u]){
		if (!matchX[v] || DFS(matchX[v])){
			matchX[v] = u;
			return true;
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

	cin >> n >> m >> k;
	FOR(i,1,k){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	for(int i=1; i<=n; i++){
		cnt++;
		res+=DFS(i);
	}
	cout << res << "\n";
	for(int i=1; i<=m; i++){
		if (matchX[i]) cout << matchX[i] << " " << i << "\n";
	}
	return 0;
}