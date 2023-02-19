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

const int MAX = 1e3+6;
const int MOD = 1e9+7;

int s[MAX][MAX];
int n,m;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> m;
	FOR(i,1,n){
		FOR(j,1,n){
			char t;
			cin >> t;
			if (t=='*') s[i][j] = 1;
			s[i][j] = s[i-1][j] + s[i][j-1] + s[i][j] - s[i-1][j-1];
		}
	}
	FOR(i,1,m){
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		// cout << x-1 << "  "<< y-1 << "\n"; 
		cout << s[u][v] - s[x-1][v] - s[u][y-1] + s[x-1][y-1] << "\n";
	}
	return 0;
}