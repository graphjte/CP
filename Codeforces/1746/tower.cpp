#include <bits/stdc++.h>
#define fi first
#define se second
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
#define ii pair<int, int>
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e9+7;
struct dsu
{
	vector<int> par;

	dsu(int n)
	{
		par.resize(n + 1);
		for (int i = 0; i <= n; i++)
			par[i] = i;
	}

	int find(int x)
	{
		if (x == par[x])
			return x;
		return par[x] = find(par[x]);
	}

	bool merge(int a, int b)
	{
		int x = find(a), y = find(b);
		if (x == y)
			return false;
		if (x > y)
			swap(x, y);
		par[y] = x;
		return true;
	}
};

struct Data{
    int u, v, d;
};

bool operator < (Data a, Data b) {
    return a.d < b.d;
}

int getBit(int x, int k) {
    return x & (1 << k);
}

int kruskal(vector<Data> &E, int n) {
    sort(E.begin(), E.end());
    dsu t(n+3);
    int sum = 0;
    int cnt = 0;
    for(auto item: E) {
        int u = item.u, v = item.v, uv = item.d;
        if (t.merge(u, v)) {
            cnt++;
            sum += uv;
        }
        if (cnt==n-1) break;
    }
    if (cnt!=n-1) return MOD;
    return sum;
} 

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    
    int cnt = 0, nRed = 0;
    int n;
    cin >> n;
    vector<Data> e;
    map<string, int> M;
    vector<vector<ii> > g(n*3+3);
    set<int> S;
    FOR(i,1,n) {
        string U, V;
        int cost, Type;
        cin >> U >> V >> cost >> Type;
        if (!M[U]) M[U] = ++cnt;
        int u = M[U]; 
        if (!M[V]) M[V] = ++cnt;
        int v = M[V]; 
        if (!Type) {
            e.push_back({u,v, cost});
            // cout << u << " " << v << " " << cost << "\n";
        }
        else{
            g[u].push_back({v, cost});
            g[v].push_back({u, cost});
            S.insert(v);
            S.insert(u);
        }
    }
    vector<int> a(S.begin(), S.end());
    nRed = S.size();
    int res = INT_MAX;
    // cout << cnt << " " << nRed << "\n";
    FOR(mask,0, (1 << nRed) - 1){
        auto E = e;
        int sum= __builtin_popcount(mask) * 10000;
        // cout << sum
        for(int i=0; i < nRed; i++){
            if (getBit(mask, i)) {
                int u = a[i];
                for(auto v: g[u]) {
                    E.push_back({u, v.first, v.second});
                }
            }
        }
        sum+= kruskal(E, cnt);
        res = min(res, sum);
        // if (res > sum) {
        //     // cout << sum << "\n";
        //     // cout << __builtin_popcount(mask) << endl;
        // }
    }
    cout << res;

    return 0;
}