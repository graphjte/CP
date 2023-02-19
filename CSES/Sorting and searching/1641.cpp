#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 5555;

int n, s;
ii a[MAX];

int Find(int l, int r, int k){
	while (l<=r){
		int mid = (l+r)/2;
		if (a[mid].fi==k) return mid;
		else if (a[mid].fi < k) l = mid+1;
		else r = mid-1;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> s;
	for(int i=1; i<=n; i++){
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a+1, a+n+1);

	for(int i=1; i<=n ;i++){
		for(int j=i+1; j<=n; j++){
			int k = Find(i+1, j-1, s - a[i].fi - a[j].fi);
			if (k!=-1){
				cout << a[i].se << " " << a[j].se << " " << a[k].se;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}