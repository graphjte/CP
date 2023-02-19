#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int vs[MAX], id[MAX], a[MAX], f[MAX], cnt, n, d[MAX];
vector<int> E;

void DFS(int u, int Id){
	vs[u]++; 
	if (vs[a[u]] < 2 && id[a[u]]==9999999) DFS(a[u], Id);
	E.push_back(u);
	id[u] = min(Id, id[a[u]]);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i], id[i] = 9999999;
	for(int i=1; i<=n; i++){
		if (!vs[i]) DFS(i, ++cnt);
	}

	for(int x: E){
		if (vs[x] == 2) d[id[x]]++;
	}
	for(int x: E){
		if (vs[x]==2) f[x] = d[id[x]]/2;
		else f[x] = f[a[x]]+1;
	}
	for(int i=1; i<=n; i++) cout << f[i] << " ";
	return 0;
}