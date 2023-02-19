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

const int MAX = 25;
const int MOD = 1e9+7;

int n, m, a[MAX][MAX], f[MAX][1 << 20];
vector<int> g[MAX];

bool Get(int mask, int k){
	return mask & (1 << (k-1));
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> m;
	FOR(i,1,m){
		int u, v;
		cin >> u >> v;
		a[u][v] = true;
		g[u].push_back(v);
	}
	f[1][1]=1;
	FOR(mask,1, (1<<n)-1){
		for(int i=1; i<=n; i++){
			for(int j: g[i]){
				if (Get(mask,i) && !Get(mask,j)){
					f[j][mask | (1 << (j-1))] += f[i][mask];
					f[j][mask | (1 << (j-1))]%= MOD;
				}
			}
		}
	}
	cout << f[n][(1<<n)-1];
	return 0;
}