#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 1e6+7;

long long n, f[MAX];
const long long MOD = 1e9+7;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	f[0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=min(6,i); j++){
			f[i]+= f[i-j];
			f[i] %= MOD;
		}
	}
	cout << f[n];
	return 0;
}