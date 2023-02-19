#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 2e5+6;
 
int n, a[MAX], b[MAX], tmp, m;
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	multiset<int> S;
 
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> tmp;
		S.insert(tmp);
	}
	for(int i=1; i<=m; i++) cin >> b[i];
	
	for(int i=1; i<=m; i++){
		auto x = S.upper_bound(b[i]);
		if (x==S.begin()) cout << -1 << "\n";
		else {
			cout << *prev(x) << "\n";
			S.erase(prev(x));
		}
	}
	return 0;
}
