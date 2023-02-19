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

vector<int> g[MAX];
int ans[MAX], n, s[MAX];

void getSize(int u, int par){
	s[u] = 1;
	for(int v: g[u]){
		if (v==par) continue;
		getSize(v, u);
		s[u]+=s[v];
	}
}

int centroid(int u, int par){
	for (int v: g[u]){
		if (v==par) continue;
		if (s[v]>n/2) return centroid(v, u);
	}
	return u;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n;
	FOR(i,1,n-1){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	getSize(1,1);
	cout << centroid(1,1);
	return 0;
}