#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, a[MAX], b[MAX];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif

	int n;
	ll sDeadline=0, Time=0,s=0;
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i] >> b[i];
		sDeadline+= b[i];
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++){
		Time+= a[i];
		s+= Time;
	}
	cout << sDeadline - s;
	return 0;
}