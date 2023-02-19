#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <set>
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
 
const int MAX = 2e5+6;
 
int n, res, k;
ii a[MAX];
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    // freopen("output.txt","w",stdout);
	#endif
	
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i].fi >> a[i].se;
	sort(a+1, a+n+1);
 
	multiset<int> S;
 
	for(int i=1; i<=n; i++){
		if (S.size()>0 && *S.begin() <= a[i].fi) S.erase(S.begin());
		if ((int)S.size() < (int)k){
			S.insert(a[i].se);
			res++;
		}
		else if (*S.rbegin() > a[i].se){
			S.erase(prev(S.end()));
			S.insert(a[i].se);
		}
	}
	cout << res;
	return 0;
}