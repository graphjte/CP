#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 2e5+6;
 
int n, f[2][MAX];
map<ii, int> m;
ii a[MAX];
 
bool cmp(ii a, ii b){
	if (a.fi == b.fi) return a.se > b.se;
	else return a.fi < b.fi;
}
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i].fi >> a[i].se;
		m[a[i]] = i;
	}
	sort(a+1, a+n+1,cmp);
	
	int Max = 0, Min = INT_MAX;
	for(int i=1; i<=n; i++){
		if (a[i].se <= Max) f[0][m[a[i]]] = 1;
		else Max = a[i].se;
	}
	for(int i=n; i >=1; i--){
		if (a[i].se >= Min) f[1][m[a[i]]] = 1;
		else Min = a[i].se;
	}
	for(int i=1; i>=0; i--){
		for(int j=1; j<=n; j++){
			cout << f[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
