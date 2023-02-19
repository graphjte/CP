#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
#define int long long
using namespace std;
 
const int MAX = 2e5+6;
 
int n, s, res, a[MAX];
 
signed main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++){
		s+= a[i];
		if (s<0) s=0;
		res = max(res, s);
	}
	if (!res){
		res = INT_MIN;
		for(int i=1; i<=n; i++) res = max(res, a[i]);
	}
	cout << res;
	return 0;
}
