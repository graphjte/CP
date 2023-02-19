#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
 
const int MAX = -1;
 
bool cmp(ii a, ii b){
	return a.se < b.se;
}
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	int n;
 
	cin >> n;
	std::vector<ii> a(n+1);
	for(int i=1; i<=n; i++){
		cin >> a[i].fi >> a[i].se; 
	}
 
	sort(a.begin()+1, a.end(),cmp);
 
	int r = 0, res= 0;
	for(int i=1; i<=n; i++){
		if (r <= a[i].fi){
			res++;
			r = a[i].se;
		}
	}
	cout << res;
	return 0;
}
