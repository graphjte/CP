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

int n, q;
ll a[MAX], s[MAX];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> q;
	FOR(i,1,n) cin >> a[i], s[i] = s[i-1] + a[i];
	FOR(i,1,q){
		int u, v;
		cin >> u >> v;
		cout << s[v] - s[u-1] << "\n";
	}
	return 0;
}