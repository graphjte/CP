#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 1e3+4;
const int MOD = 1e9+7;

int n, f[MAX][MAX];
char a[MAX][MAX];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	f[1][0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=1;j<=n; j++){
			cin >> a[i][j];
			if (a[i][j]=='.') f[i][j] = (f[i-1][j]+ f[i][j-1])%MOD;
			// cout << f[i][j] << " \n"[j==n];
		}
	}
	cout << f[n][n];
	return 0;
}