#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, a[MAX], k;

bool Check(long long val){
	ll sum = 0;
	int cnt = 1;
	for(int i=1; i<=n; i++){
		if (sum + a[i] > val){
			sum = a[i];
			cnt++;
		}
		else{
			sum += a[i];
		}
		if (sum > val) return false;
	}
	return cnt <= k;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	ll s=0, res=0;

	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		s+= a[i];
	}
	ll l = 0, r = s;
	while (l<=r){
		ll mid = (l+r)/2;
		if (Check(mid)){
			r = mid-1;
			res = mid;
		}
		else l = mid+1;
	}
	// cout << Check(99) << "\n";
	cout << res;
	return 0;
}