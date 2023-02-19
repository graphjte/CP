#include <bits/stdc++.h>
#define int long long 
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

struct Edge
{
	int u, v, w, num;
};

bool operator < (Edge a, Edge b){
	return a.w < b.w;
}

Edge E[MAX];
int n, m, res[MAX], par[MAX], Pre[MAX];
vector<ii> g[MAX];

void DFS(int u, int dest){
	for(ii tmp: g[u]){
		int v = tmp.fi;
		if (Pre[v]) continue;
		Pre[v] = u;
		DFS(v, dest);
	}
}

void Trace(int dest, int source, int weigh){
	while (dest!=source){
		for(auto [v, id]: g[dest]){
			if (v==Pre[dest]) {
				if (E[id].w==weigh){
					res[id] = false;
				}
				dest = v;
			}
		}
	}	
}

int Find(int x){
	if (x==par[x]) return x;
	return par[x] = Find(par[x]);
}

bool Union(int id){
	int u = E[id].u , v = E[id].v;
	int x = Find(u), y = Find(v);
	if (x==y) return false;
	if (x > y) swap(x, y);
	par[y] = x;
	return true;
}

int32_t main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> m;
	FOR(i,1,n) par[i] = i;
	FOR(i,1,m){
		cin >> E[i].u >> E[i].v >> E[i].w;
		E[i].num = i;
	}
	sort(E+1, E+m+1);
	FOR(i,1,m){
		int u = E[i].u, v = E[i].v;
		if (!Union(i)){
			FOR(i,1,n) Pre[i] = 0;
			DFS(u,v);
			Trace(v,u, E[i].w);
		}
		else{
			g[u].push_back(ii(v,i));
			g[v].push_back(ii(u,i));
			res[i] = true;
		}
	}
	ii rr=ii(0,0);
	FOR(i,1,m){
		if (res[i]) {
			rr.fi++;
			rr.se+= E[i].w;
		}
	}
	cout << rr.fi <<  " " << rr.se; 
	return 0;
}