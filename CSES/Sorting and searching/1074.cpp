#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, a[MAX];

ll Cal(int val){
	ll ret = 0;
	for(int i=1; i<=n; i++){
		ret += abs(a[i] - val);
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	
	int l = 1, r = 1e9;
	while (l<r){
		int mid = (l+r)/2;
		ll f1 = Cal(mid);
		ll f2 = Cal(mid+1);
		if (f1 > f2){
			l = mid+1;
		}
		else r = mid;
	}
	cout << Cal(l);
	return 0;
}