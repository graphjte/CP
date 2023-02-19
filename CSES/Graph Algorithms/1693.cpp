#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e9+7;

int n, m, In[MAX], Out[MAX];
vector<int> E, g[MAX];

void DFS(int u){

	while (g[u].size()){
		int v = g[u].back();
		g[u].pop_back();
		DFS(v);
	}
	E.push_back(u);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> m;
	int d=0, in=0, out=0, st, en;
	for(int i=1; i<=m; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		Out[a]++; In[b]++;
	}
	for(int i=1; i<=n; i++){
		if (In[i]==Out[i]) d++;
		if (In[i] - Out[i] ==1) in++, en = i;
		if (In[i] - Out[i] ==-1) out++, st = i;
	}
	DFS(1);
	reverse(E.begin(), E.end());
	if (st!=1 || en!=n || d!=n-2 || in!=1 || E.size()!=m+1 || out!=1) {
		// cout << d << " " << in << " " << out << E.size() << "\n";
		cout << "IMPOSSIBLE";
		return 0;
	}
	for(int v: E) cout << v << " ";
	return 0;
}