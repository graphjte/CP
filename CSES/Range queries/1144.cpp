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

const int MAX = 6e5+6;
const int MOD = 1e9+7;

int n, Q, a[MAX], B[MAX];
char Type[MAX];
ii b[MAX];
vector<int> d;

int Find(int x){
	return lower_bound(all(d), x) - d.begin() + 1;
}

void Update(int x, int val){
	for(; x <MAX; x+=x&-x) B[x]+= val;
}

int Query(int x){
	int ret = 0;
	for(; x > 0; x-=x&-x) ret+= B[x];
	return ret;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> Q;
	FOR(i,1,n){
		cin >> a[i];
		d.push_back(a[i]);
	}
	FOR(i,1,Q){
		cin >> Type[i] >> b[i].fi >> b[i].se;
		d.push_back(b[i].fi-1);
		d.push_back(b[i].se);
	}
	sort(all(d));
	FOR(i,1,n){
		Update(Find(a[i]),1);
	}
	FOR(i,1,Q){
		if (Type[i] == '?'){
			cout << Query(Find(b[i].se)) - Query(Find(b[i].fi-1)) << "\n";
		}
		else{
			Update(Find(a[b[i].fi]),-1);
			a[b[i].fi] = b[i].se;
			Update(Find(a[b[i].fi]),1);
		}
	}
	return 0;
}