#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 11111;

ll L[MAX], f[MAX], t;

void Init(){
	L[1] = 1;
	f[1] = 9;
	for(int i=2; i<=17; i++){
		L[i] = L[i-1]*10; 
		f[i] = 9*L[i]*i+ f[i-1];
	}
}

void Cal(ll n){
	int x = lower_bound(f+1, f+17+1, n) - f - 1;
	ll remain = n - f[x];
	ll nth = remain/(x+1) + L[x+1] - 1 + (remain%(x+1) > 0);
	int tmp = remain%(x+1);
	if (!tmp) tmp = x+1;
	string s;
	stringstream cc;
	// cout << nth << "\n";
	// cout << tmp << "\n";
	cc << nth;
	cout << cc.str()[tmp-1] << "\n";

}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	Init();
	cin >> t;
	while (t--){
		ll n;
		cin >> n;
		Cal(n);
	}
	return 0;
}