#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
#define iii pair<int, ii>
using namespace std;

const int MAX = 2e5+6;

int n, par[MAX], m, nEdges;
ll res;
vector<iii> E;

int Find(int x){
	if (x==par[x]) return x;
	return par[x] = Find(par[x]);
}

bool Union(int a, int b){
	int x = Find(a), y = Find(b);
	if (x==y) return false;
	if (x > y) swap(x, y);
	par[y] = x;
	return true;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> m;
	for(int i=1; i<=n; i++) par[i] = i;
	for(int i=1; i<=m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		E.push_back(iii(w,ii(u,v)));
	}

	sort(E.begin(), E.end());

	for(iii t: E){
		if (Union(t.se.fi, t.se.se)) {
			res+= t.fi;
			nEdges++;
		}
		if (nEdges == n-1) break;
	}
	if (nEdges < n-1) cout << "IMPOSSIBLE";
	else cout << res;
	return 0;
}