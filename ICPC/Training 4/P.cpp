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

int Solve2(int x, int y, int z, int k){
	int res = 0;
	if (x >= k) {
		res = max(res, Solve2(x%k,y,z,k) + y*z*(x/k));
	}
	if (y >= k) {
		res = max(res, Solve2(x,y%k,z,k) + z*x*(y/k));
	}
	if (z >= k) {
		res = max(res, Solve2(x,y,z%k,k) + x*y*(z/k));
	}
	return res;
}


int Solve(int x, int y, int z, int k){
	int res = 0;
	if (x < y) swap(x, y); 
	if (x < z) swap(x, z); 
	if (y < z) swap(z, y); 
	if (x/k<=1 && y/k<=1 && z/k<=1){
		return Solve2(x,y,z,k);
	}

	if (x >= k) {
		res = max(res, Solve(k+x%k,y,z,k) + y*z*(x/k-1));
	}
	if (y >= k) {
		res = max(res, Solve(x,k+y%k,z,k) + z*x*(y/k-1));
	}
	if (z >= k) {
		res = max(res, Solve(x,y,k+z%k,k) + x*y*(z/k)-1);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif
	int T, x, y, z, k;
	cin >> T;
	while (T--){
		cin >> x >> y >> z >> k;
		cout << Solve(x,y,z,k) << "\n";
	}
	return 0;
}