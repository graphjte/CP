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

int n, B[MAX], a[MAX];

void Update(int i, int val){
	for(; i<=n; i+=i&-i) B[i]+=val;
}

int Get(int x){
	int ret = 0;
	for(; x >0; x-=x&-x) ret+= B[x];
	return ret;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n;
	FOR(i,1,n) cin >> a[i], Update(i,1);
	FOR(i,1,n){
		int q;
		cin >> q;
		int l = 1, r = n;
		int ret = 0;
		while (l<=r){
			int mid = (l+r)/2;
			if (Get(mid)>=q){
				ret = mid;
				r = mid-1;
			}
			else l = mid+1;
		}
		cout << a[ret] << " ";
		Update(ret, -1);
	}
	return 0;
}