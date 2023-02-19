#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, a[MAX], k;
map<int, int> f;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	int p = 1, cnt = 1;

	ll res = 0;
	if (k) res++;
	f[a[1]] = true;

	for(int i=2; i<=n; i++){
		if (f[a[i]]) f[a[i]]++;
		else{
			f[a[i]]++;
			cnt++;
			while (p <= i && cnt>k){
				f[a[p]]--;
				if (!f[a[p]]) cnt--;
				p++;
			}
		} 
		res+= i - p + 1;
	}
	cout << res;
	return 0;
}