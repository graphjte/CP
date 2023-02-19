#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 1e6+7;
const int MOD = 1e9+7;

int n, f[MAX], a[MAX], s;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> s;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	// for(int i=1; i<=s; i++) f[i] = 10000000;
	f[0] = 1;

	for(int j=1; j<=s; j++){
		for(int i=1; i<=n; i++){
			if (j - a[i] >=0) 
			{
				f[j] += f[j-a[i]];
				f[j]%= MOD;
			}
		}
	}
	// if (f[s] == 10000000) cout << -1;
	cout << f[s];
	return 0;
}