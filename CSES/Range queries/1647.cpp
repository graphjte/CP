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

int n, a[18][MAX], q, L;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> q;
	FOR(i,1,n){
		cin >> a[0][i];
	}
	L = log2(n);
	FOR(j,1,L){
		FOR(i,1,n-(1<<j)+1){
			a[j][i] = min(a[j-1][i], a[j-1][i+(1<<(j-1))]);
		}
	}
	FOR(i,1,q){
		int L, R;
		cin >> L >> R;
		int t = log2(R-L+1);
		cout << min(a[t][L], a[t][R-(1<<t)+1]) << "\n";
	}
	return 0;
}