#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 2e5+6;
 
int n, a[MAX], f[MAX], res;
 
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
 
	int Last = 1;
	f[1] = a[1];
	for(int i=2; i<=n; i++){
		int pos = upper_bound(f+1,f+Last+1, a[i]) - f;
		if (pos > Last) {
			Last++;
			f[Last] = a[i];
		}
		else f[pos] = a[i];
	}
	cout << Last;
	return 0;
}
