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

int DP(int Time, int pos, int duration){
	//stop
	int res = 0;
	if (Time >= t[pos-1]) res = max(res, DP(Time-t[pos-1],pos-1, dd));
	if (dd>0) res = max(res, DP(Time-5, pos, dd-1)+(f[pos]-dd*d[pos]));
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> T;
	while (T--){
		cin >> n >> h;
		h*=12;
		FOR(i,1,n){
			cin >> f[i];
		}
		FOR(i,1,n){
			cin >> d[i];
		}
		FOR(i,1,n-1){
			cin >> t[i];
		}
		FOR(i,1,n){
			for(int duration = 0, fish=f[i]; fish-=d[i]; duration+=5)
				res = max(res, DP(h,i,duration));
		}
		cout << res;
	}
	return 0;
}