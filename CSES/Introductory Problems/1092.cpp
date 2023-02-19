#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 1e6+6;

ll n;
vector<int> l,r;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	ll s = n*(n+1)/2;
	if (s&1) cout << "NO";
	else{
		ll t = s/2;
		// cout << t << "\n";
		for(int i=n; i>=1; i--){
			if (t > 0 && t >= i){
				r.push_back(i);
				t-=i;
			}
			else l.push_back(i);
		}
		cout << "YES" << "\n";
		cout << r.size() << "\n";
		sort(r.begin(), r.end());
		for(int x: r) cout << x << " ";
		cout << "\n" << l.size() << "\n";
		for(int x: l) cout << x << " ";
	}
	return 0;
}