#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 2e5+6;
 
int n, a[MAX], d, res;
map<int, int> Last;
 
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
	for(int i=1; i<=n; i++){
		if (!Last[a[i]]) d = d+1;
		else d = min(i - Last[a[i]], d+1);
		Last[a[i]] = i;
		res = max(res, d);
	}
	cout << res;
	return 0;
}
