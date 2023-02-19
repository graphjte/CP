#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, a[MAX], res;

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
	}
	vector<int> f(n+1, INT_MAX);
	f[0] = 0; 
	for(int i=1; i<=n; i++){
		auto t = lower_bound(f.begin(), f.end(), a[i]);
		*t = min(*t, a[i]);
		res = max(res, (int)(t - f.begin()));
		// if (i==1) cout << typeid(n).name();
	}
	cout << res;
	return 0;
}