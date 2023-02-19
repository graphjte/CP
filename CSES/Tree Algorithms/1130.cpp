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

int n, f[2][MAX];
vector<int> g[MAX];

void DFS(int u, int par){
	int s= 0;
	for(int v: g[u]){
		if (v==par) continue;
		DFS(v, u);
		f[0][u] += f[1][v];
		f[1][u] += f[1][v];
		if (f[0][v] - f[1][v]+1 > s) s =  f[0][v] - f[1][v] + 1;
	}
	f[1][u]+=s;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << "Hello";

	cin >> n;
	FOR(i,1,n-1){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	DFS(1,0);
	cout << max(f[0][1], f[1][1]);
	return 0;
}