#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define ll long long
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e9+7;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	int n;
	cin >> n;
	vector<ll> a(n+1);
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a.begin()+1, a.end(), greater<ll>());
	ll res = 0;
	for(int i=1; i<=n/2; i++){
		res+= a[i];
	}
	cout << res;
	return 0;
}