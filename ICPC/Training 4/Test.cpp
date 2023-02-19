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

const int MAX = 5e6+6;
const int MOD = 1e9+7;

int n, a[MAX], Mn = 1e15, Mx = -1e15, s, L, Last = 0;

int32_t main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> s >> L;
	FOR(i,1,n) cin >> a[i];
	n++;
	a[n] = 1e15;
	int l = 1, res = 0;
	FOR(i,1,n){
		if (max(Mx,a[i]) - min(Mn,a[i]) > s){
			int LastLast = Last;
			Last = i-l;
			while (max(Mx,a[l-1]) - min(Mn,a[l-1])<=s && l>1 && LastLast > L){
				Mn = min(Mn, a[l-1]);
				Mx = max(Mx, a[l-1]);
				l--;	
				LastLast--;
				Last++;
			} 
			res++;
			l = i;
			Mn = a[i];
			Mx = a[i];
			if (Last<L){
				cout << -1;
				return 0;
			}
		}
		Mn = min(Mn, a[i]);
		Mx = max(Mx, a[i]);
	}
	cout << res;
	return 0;
}