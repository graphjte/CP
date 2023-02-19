#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 1e5+6;
const int MOD = 1e9+7;

int n, a[MAX], f[MAX][111], m;

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
	}

	for(int i=0; i<=m+1; i+=3) f[0][i] = 1;

	for(int i=1; i<=n; i++){
		if (a[i]){
			f[i][a[i]] = f[i-1][a[i]-1] + f[i-1][a[i]], f[i][a[i]]%=MOD;
			if (a[i] < m) f[i][a[i]]+= f[i-1][a[i]+1], f[i][a[i]]%=MOD;
		}
		else{
			for(int j=1; j<=m; j++){
				f[i][j] = f[i-1][j-1] + f[i-1][j];
				f[i][j]%= MOD;
				f[i][j] +=f[i-1][j+1];
				f[i][j]%= MOD;
			}
		}
	}
	int res = 0;
	for(int i=1; i<=m; i++){
		res+= f[n][i];
		res%= MOD;
	}
	cout << res;
	return 0;
}