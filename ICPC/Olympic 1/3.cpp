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
const ll MOD = 1e9+7;

ll Pow(ll a, ll k){
	if (k==1) return a;
	ll tmp = Pow(a,k/2);
	tmp = (tmp*tmp)%MOD;
	if (k&1) {
		tmp*=a;
		tmp%=MOD;
	}
	return tmp;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif
	ll n, L;
	cin >> n >> L;
	// ll res = ((Pow(4,n+1)-1 + MOD)%MOD*Pow(3,MOD-2))%MOD;
	// cout << res;
	cout << (1^15) << "\n";
	// cout << ((L*L)%MOD*res)%MOD;
	return 0;
}