#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 2e5+6;
 
int n, a[MAX], s, res;
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> s;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	int i = 1, j = n;
	while (i < j){
		if (a[i] + a[j] <= s) i++, j--;
		else j--;
		res++;
	}
	cout << res + (i==j);
	return 0;
}
