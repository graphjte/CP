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

int sz[MAX], cnt[MAX], n, a,b, processed[MAX], mxDeep;
ll ans, Bit[MAX];
vector<int> g[MAX];

int getSize(int u, int par=-1){
	sz[u] = 1;
	for(int v: g[u]){
		if (v==par || processed[v]) continue;
		sz[u]+= getSize(v, u);
	}
	return sz[u];
}

int getCentroid(int u, int size, int par = -1){
	for(int v: g[u]){
		if (v==par || processed[v]) continue;
		if (sz[v] >= size/2) return getCentroid(v, size, u);
	}
	return u;
}

void Update(int u, int cnt){
	for(++u; u<=n; u+=u&-u) Bit[u]+=cnt;
}

ll Query(int u){
	ll tmp = 0;
	for(++u; u>0; u-=u&-u) tmp+= Bit[u];
	return tmp;
}

void calc(int u, int par, bool filling, int curDeep){
	if (curDeep > b) return;
	mxDeep = max(mxDeep, curDeep);
	if (filling) Update(curDeep,1);
	else ans+= Query(b- curDeep) - Query(a- curDeep-1);
	for(int v: g[u]){
		if (v==par || processed[v]) continue;
		calc(v,u,filling,curDeep+1);
	}
}


void centroidDecomp(int node){
	int centroid = getCentroid(node, getSize(node));
	processed[centroid] = true;
	mxDeep = 0;
	// cnt[0] = 1;
	for(int v: g[centroid]){
		if (processed[v]) continue;
		calc(v,v,0,1);
		calc(v,v,1,1);
	}
	for (int i = 1; i <= mxDeep; i++) Update(i, -1*(Query(i) - Query(i-1)));
	// memset(Bit,0,sizeof Bit);
	for(int v: g[centroid]) if (!processed[v]) centroidDecomp(v);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> a >> b;
	FOR(i,1,n-1){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	Update(0,1);
	centroidDecomp(1);
	cout << ans;
	return 0;
}