#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 100000;

int n;
ll f[MAX];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	f[1] = 0;
	f[2] = 0;
	f[3] = 8;

	for(ll i=1; i <= n;i++){
		if (i > 3) f[i] = f[i-1] + 18 + (i-4)*8 - 2;
		cout << i*i*(i*i-1)/2 - f[i]<< "\n";
	}
	return 0;
}