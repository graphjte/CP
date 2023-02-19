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
	int T;
	cin >> T;
	while (T--){
		ll x, y;
		cin >> x >> y;
		if (x >= y){
			if (x&1){
				cout << (x-1)*(x-1) + y << "\n";
			}
			else{
				cout << x*x - y + 1 << "\n";
			}
		}
		else{
			if (y&1){
				cout << y*y-x+1 << "\n";
			}
			else{
				cout << (y-1)*(y-1) + x << "\n";
			}
		}
	}
	return 0;
}