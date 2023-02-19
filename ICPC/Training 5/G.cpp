#include <bits/stdc++.h>
using namespace std;

int n, a[11111], res=0;

int main(int argc, char const *argv[])
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i]+= a[i-1];
		res = max(res, a[i]);
	}
	cout << 100 + res;
	return 0;
}