#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = -1;
const int MOD = 1e9+7;

ll n;

ll Pow(ll n){
	if (n==1) return 2;
	ll res = Pow(n/2);
	res*=res;
	if (n&1) res*=2;
	return res % MOD;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	cout << Pow(n);
	return 0;
}