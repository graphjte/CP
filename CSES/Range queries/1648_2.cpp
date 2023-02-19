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
ll a[MAX], B[MAX];

ll Query(int x){
	ll ret = 0;
	for(; x>0; x-=x&-x) ret+= B[x];
	return ret;
}

void Update(int x, ll k){
	for(; x <=n; x+=x&-x) B[x]+= k;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> q;
	FOR(i,1,n) cin >> a[i];
	FOR(i,1,n) Update(i, a[i]);
	FOR(i,1,q){
		int t, u;
		ll v;
		cin >> t >> u >> v;
		if (t == 1){
			Update(u,v-a[u]);
			a[u] = v;
		} else{
			cout << Query(v) - Query(u-1) << "\n";
		}
	}
	return 0;
}