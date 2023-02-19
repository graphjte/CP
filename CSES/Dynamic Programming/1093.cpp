#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 555;
const int MAX_S = 2e5+6;
const int MOD = 1e9+7;

int n, f[MAX][MAX_S];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	f[0][0] = 1;
	int s = (n+1)*n/4;
	if ((n+1)*n > 4*s) {
		cout << 0;
		return 0;
	}
	// cout << s << "\n";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=s; j++){
			f[i][j] = f[i-1][j];
			if (j >= i) f[i][j] += f[i-1][j-i], f[i][j]%= MOD;
		}
	}
	cout << f[n][s];
	return 0;
}