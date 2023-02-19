#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 2e5+6;
 
int Next[MAX][31];
int n, q, m;
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> q;
	for(int i=1; i<=n; i++) cin >> Next[i][0];
	m = 30;
	for(int j=1; j<=m; j++){
		for(int i=1; i<= n; i++){
			Next[i][j] = Next[Next[i][j-1]][j-1];
		}
	}
	while (q--){
		int u, t;
		cin >> u >> t;
		for(int i=m; i>=0; i--){
			if (t >= (1 << i)) {
				u = Next[u][i];
				t-= 1 << i;
			}
		}
		cout << u << "\n";
	}
	return 0;
}