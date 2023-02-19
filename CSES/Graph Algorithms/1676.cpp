#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, m, par[MAX], nComp, Size[MAX], mxSize;

int Find(int x){
	if (x==par[x]) return x;
	return par[x] = Find(par[x]);
}

bool Union(int a, int b){
	int x = Find(a), y = Find(b);
	if (x==y) return 0;
	if (Size[x] < Size[y]) swap(x, y);
	Size[x]+= Size[y];
	par[y] = x;
	mxSize = max(mxSize, Size[x]);
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
	for(int i=1; i<=n; i++) par[i] = i, Size[i] = 1;
	nComp = n;
	for(int i=1; i<=m; i++) {
		int u,v;
		cin >> u >> v;
		nComp-= Union(u,v);
		cout << nComp << " " << mxSize << "\n";
	}
	return 0;
}