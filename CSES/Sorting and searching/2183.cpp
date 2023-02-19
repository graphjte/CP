#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

ll sum, a[MAX],n;

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
	sort(a+1, a+n+1);

	for(int i=1; i<=n; i++){
		if (a[i] > sum + 1) {cout << sum + 1; return 0;}
		sum+= a[i];
	}
	cout << sum + 1;
	return 0;
}