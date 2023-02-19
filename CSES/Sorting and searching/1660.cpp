#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 2e5+6;
 
int n, a[MAX];
long long s[MAX],x;
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> x;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	int ans = 0;
	for(int i=1; i<=n; i++){
		if (binary_search(s, s+i, s[i]- x)) ans++;
	}
	cout << ans;
	return 0;
}
