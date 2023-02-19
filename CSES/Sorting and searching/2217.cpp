#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 2e5+6;
 
int n, a[MAX], pos[MAX], res, m;
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	pos[n+1] = n+1;
	for(int i=2; i<=n; i++){
		if (pos[i] < pos[i-1]) res++;
	}
	// cout << res+1;
	for(int i=1; i<=m; i++){
		int u,v;
		cin >> u >> v;
		swap(a[u],a[v]);
		u = a[u], v= a[v];
		if (u > v) swap(u, v);
 
		for(int j=u; j<= u+1; j++){
			if (pos[j] < pos[j-1]) res--; 
		}
		for(int j=v; j<= v+1; j++){
			if (j-1 == u) continue;
			if (pos[j] < pos[j-1]) res--; 
		}
		swap(pos[u], pos[v]);
		for(int j=u; j<= u+1; j++){
			if (pos[j] < pos[j-1]) res++; 
		}
		for(int j=v; j<= v+1; j++){
			if (j-1 == u) continue;
			if (pos[j] < pos[j-1]) res++; 
		}
		cout << res+1 << "\n";
	}
	return 0;
}
