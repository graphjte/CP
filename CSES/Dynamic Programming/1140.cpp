#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n;
ll a[MAX], dp[MAX];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	int n;
	vector<ii> d;

	cin >> n;
	for(int i=1; i<=n; i++){
		int l, r, v;
		cin >> l >> r >> v;
		a[i] = v;
		d.push_back(ii(l,-i));
		d.push_back(ii(r,i));
	}
	sort(d.begin(), d.end());

	ll Max = 0;
	for(auto [day,id]: d){
		if (id<0) {
			dp[-id] = Max + a[-id];
		}
		else Max = max(Max, dp[id]);
	}
	cout << Max;
	return 0;
}