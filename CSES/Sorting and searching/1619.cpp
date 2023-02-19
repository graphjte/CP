#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = -1;
 
int n, res, sum;
 
vector<ii> a;
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	for(int i=1; i<=n; i++){
		int u, v;
		cin >> u >> v;
		a.push_back(ii(u,1));
		a.push_back(ii(v,-1));
	}
	sort(a.begin(), a.end());
	for(auto [x,y]: a){
		sum+= y;
		res = max(res, sum);
	}
	cout << res;
	return 0;
}
