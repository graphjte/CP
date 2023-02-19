#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 2e5+6;
 
int n, a[MAX];
long long s[MAX],x;
map<ll, int> M;
 
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
		s[i] = s[i-1] + a[i]%n+n;
		s[i]%=n;
	}
	ll ans = 0;
	M[0]++;
	for(int i=1; i<=n; i++){
		ans+= M[s[i]];
		M[s[i]]++;
	}
	cout << ans;
	return 0;
}
