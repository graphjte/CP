#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = -1;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	int n;
	cin >> n;
	ll res = 0;
	vector<int> a(n+1);
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if (a[i] < a[i-1]) {
			res += a[i-1] - a[i];
			a[i] = a[i-1];
		}
	}
	cout << res;
	return 0;
}