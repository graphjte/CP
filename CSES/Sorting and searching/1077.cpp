#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, a[MAX], k;

void Solve(){
	priority_queue<ii> L;
	priority_queue<ii, vector<ii>, greater<ii> > R;
	ll sum = 0, sL=0;
	int nL = 0;
	int m = (k+1)/2;
	for(int i=1; i <=n; i++){
		sum+= a[i];
		while (R.size() && R.top().se <= i - k) R.pop();
		while (L.size() && L.top().se <= i - k) L.pop();
		if (nL < m){
			R.push(ii(a[i],i));
			sL+= R.top().fi;
			L.push(R.top()); R.pop();
			nL++;
		}
		else{
			L.push(ii(a[i],i));
			sL+= a[i]; sL-= L.top().fi;
			R.push(L.top()); L.pop();
		}
		while (L.size() && L.top().se <= i - k) L.pop();
		if (i < k) continue;
		cout << sum - 2*sL + (ll)(2*m - k)*(ll)L.top().fi << " ";
		sum-= a[i-k+1];
		if (a[i-k+1] <= L.top().fi) nL--, sL-=a[i-k+1];
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	Solve();
	return 0;
}