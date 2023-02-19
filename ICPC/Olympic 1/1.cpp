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

int k, n, q;
int a[MAX], Next[MAX], inQ[MAX], Last[MAX];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	while (cin >> k >> n >> q){
		set<ii> Set;
		int res = 0, Size = 0;
		FOR(i,1,q){
			cin >> a[i];
			Next[i] = 0;
		}
		FOR(i,0,n){
			Last[i] = q+10;
			inQ[i] = 0;
		}
		FORD(i,q,1){
			Next[i] = Last[a[i]];
			Last[a[i]] = i;
		}
		FOR(i,1,q){
			if (Size < k){
				if (inQ[a[i]]) {
					Set.erase(ii(i,a[i]));
					Set.insert(ii(Next[i],a[i]));
					continue;
				}

				Set.insert(ii(Next[i],a[i]));
				inQ[a[i]] = true;
				Size++;
				Set.erase(ii(i,a[i]));
				Set.insert(ii(Next[i],a[i]));
				res++;
			}
			else{
				if (inQ[a[i]]) {
					Set.erase(ii(i,a[i]));
					Set.insert(ii(Next[i],a[i]));
					continue;
				}
				inQ[(*prev(Set.end())).se] = false;
				Set.erase(prev(Set.end()));
				Set.insert(ii(Next[i],a[i]));
				inQ[a[i]] = true;
 				res++;
			}
		}
		cout << res << "\n";
	}
	return 0;
}