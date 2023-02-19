#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 1e5+6;

int n, f[1003][MAX], val[1003], cost[1003], s;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> s;
	for(int i=1; i<=n; i++){
		cin >> cost[i];
	}
	for(int i=1; i<=n; i++){
		cin >> val[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=s; j++){
			f[i][j] = f[i-1][j];
			f[i][j] = max(f[i][j], f[i][j-1]);
			if (j >= cost[i]) f[i][j] = max(f[i][j], f[i-1][j-cost[i]] + val[i]);
		}
	}
	cout << f[n][s];
	return 0;
}