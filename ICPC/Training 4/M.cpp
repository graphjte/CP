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

ll n, m, f[MAX], d[MAX], par[MAX], res;

int Find(int x){
	if (x==par[x]) return x;
	// return par[x] = Find(par[x]);
	par[x] = Find(par[x]);
	return par[x];
}

void Union(int u, int v){
	int x = Find(u), y = Find(v);
	if (x==y) return;
	if (x > y) swap(x, y);
	par[y] = x;
	d[x]+= d[y];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> m;
	f[0] = 1;
	FOR(i,1,n){
		d[i] = 1;
		par[i] = i;
		f[i] = (f[i-1]*i)%MOD;
	}
	FOR(i,1,m){
		int u, v;
		cin >> u >> v;
		u++; v++;
		Union(u,v);
	}
	FOR(i,1,n){
		// cout << d[i]  << " " << par[i]<< "\n"; 
		if (i==par[i] && d[i]>2){
			res+= f[d[i]];
			res%= MOD;
		}
	}
	cout << res;
	return 0;
}