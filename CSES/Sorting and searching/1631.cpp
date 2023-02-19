#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n;
ll s, a[MAX];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	for(int i=1 ;i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++){
		s+= a[i];
	}

	if (s - a[n] < a[n]) cout << a[n]*2;
	else cout << s;
	return 0;
}