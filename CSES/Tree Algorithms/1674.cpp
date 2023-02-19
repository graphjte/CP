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

int n, c[MAX];
vector<int> g[MAX];

void DFS(int u){
	for(int v: g[u]){
		DFS(v);
		c[u]+= c[v]+1;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n;
	FOR(i,2,n){
		int tmp;
		cin >> tmp;
		g[tmp].push_back(i);
	}		
	DFS(1);
	FOR(i,1,n) cout << c[i] << " ";
	return 0;
}