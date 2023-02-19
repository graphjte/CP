#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 1e6+7;
const int MOD = 1e9+7;

int n, a[MAX], aMax;
ll f[MAX][2];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		aMax = max(a[i], aMax);
	}
	f[1][0] = f[1][1] = 1ll;
	for(int i=2; i<=aMax; i++){
		f[i][0] = (f[i-1][0]*4 + f[i-1][1])% MOD; 
		f[i][1] = (f[i-1][1]*2 + f[i-1][0])%MOD;
	}
	for(int i=1; i<=n; i++){
		cout << (f[a[i]][0] + f[a[i]][1])%MOD << "\n";
	}
	return 0;
}