#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = -1;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	int n;
	ll res = LLONG_MAX, s = 0;
	cin >> n;
	int a[22];
	for(int i=1; i<=n; i++){
		cin >> a[i];
		s+= a[i];
	}
	for(int mask = 1; mask < (1 << n); mask++){
		ll sum = 0;
		for(int i=0; i < n; i++){
			if (mask & (1 << i)) sum+= a[i+1];
		}
		res = min(res, abs(s - sum*2));
	}
	cout << res;
	return 0;
}