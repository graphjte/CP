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

int t[MAX*4], c[MAX], d[MAX], par[MAX], n;
int Id[MAX], Head[MAX], pos[MAX], k, a[MAX], cnt;
vector<int> g[MAX];

void DFS(int u){
	c[u] = 1; d[u] = d[par[u]] + 1;
	int idMx = -1;
	for(int i=0; i < g[u].size(); i++){
		int v = g[u][i];
		if (v==par[u]) continue;
		par[v] = u;
		DFS(v);
		c[u]+= c[v];
		if (idMx==-1 || c[v]>c[g[u][idMx]]){
			idMx = i;
		}
	}
	if (idMx!=-1) swap(g[u][idMx], g[u][0]);
}

void HLD(int u, int curHead){
	Head[u] = curHead;
	pos[u] = ++cnt;
	Id[cnt] = u;
	if (g[u][0]==par[u]) return;
	HLD(g[u][0], curHead);
	for(int i=1; i < g[u].size(); i++){
		int v = g[u][i];
		if (v==par[u]) continue;
		HLD(v,v);
	}
}

void Update(int id, int l, int r, int pos, int val){
	if (l==r){
		t[id] = val;
		return;
	}
	int mid = (l+r)/2;
	if (pos<=mid) Update(id*2,l,mid,pos,val);
	else Update(id*2+1,mid+1,r,pos,val);
	t[id] = max(t[id*2],t[id*2+1]);
}

int ITQuery(int id, int l, int r, int u, int v){
	if (v<l || r<u) return 0;
	if (u<=l && r<=v){
		return t[id];
	}
	int mid = (l+r)/2;
	return max(ITQuery(id*2,l,mid,u,v), ITQuery(id*2+1,mid+1,r,u,v));
}

void Build(int id, int l, int r){
	if (l==r){
		t[id] = a[Id[l]];
		return;
	}
	int mid = (l+r)/2;
	Build(id*2,l,mid);
	Build(id*2+1,mid+1,r);
	t[id] = max(t[id*2], t[id*2+1]);
}

int Query(int u, int v){
	int res = 0;
	while (Head[u]!=Head[v]){
		if (d[Head[u]] > d[Head[v]]) swap(u,v); //v sau hon
		res = max(res, ITQuery(1,1,n,pos[Head[v]], pos[v]));
		v = par[Head[v]];
	}
	if (pos[u] > pos[v]) swap(u, v);
	res = max(res, ITQuery(1,1,n,pos[u],pos[v]));
	return res;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> k;
	FOR(i,1,n) cin >> a[i];//, cout << a[i] << "\n";
	FOR(i,1,n-1){
		int u, v;
		cin >> u >> v;
		// cout << u << " " << v << endl;
		// g[u].push_back(v);
		// g[v].push_back(u);
	}
	// cout << "XONG";
	// return 0;
	DFS(1);
	HLD(1,1);
	Build(1,1,n);
	while (k--){
		int Type, u,v;
		cin >> Type >> u >> v;
		if (Type==1){
			Update(1,1,n,pos[u],v);
		}
		else cout << Query(u,v) << " ";
	}
	return 0;
}