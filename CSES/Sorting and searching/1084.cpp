#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 2e5+6;
 
int n, m, a[MAX], b[MAX], r, res;
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> m >> r;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=m; i++) cin >> b[i];
 
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);
 
	int p = 1;
 
	for(int i=1; i<=n; i++){
		if (p > m) break;
		while (p+1<=m && b[p] < a[i]-r) p++;
		if (p<=m && a[i]-r<=b[p] && b[p]<=a[i]+r) p++, res++;
	}
	cout << res;
	return 0;
 
}
