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

const int MAX = 1e6+6;
const int MOD = 1e9+7;

int a[MAX], b[MAX], n, q;

int32_t main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n;
	FOR(i,1,n) {
		cin >> a[i];
		b[i] = a[i];	
		b[i]^=b[i-1];
	}
	int L = 0, R = n;
	cin >> q;
	FOR(i,1,q){
		string tmp;
		int tt;
		cin >> tmp;
		if (tmp=="POP"){
			L++;
			FOR(i,L,R) b[i]^=a[L-1];
		}
		else if (tmp=="PUSH"){
			cin >> tt;
			R++;
			a[R] = tt;
			b[R] = b[R-1]^a[R];
		}
		else{
			int l, r, dem=0;
			cin >> l >> r;
			FOR(i,L,R){
				if (b[i]>=l && b[i]<=r) dem++;
			}
			// if (l==3){
				// cout << "\n";
				// FOR(i,L,R) cout << b[i] << " ";
				// cout << "\n";
			// }
			cout << dem << "\n";
		}
	}
	return 0;
}