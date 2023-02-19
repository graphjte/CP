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

int t[2][MAX*4], n, q;
int a[MAX];

void Update(int id, int l, int r, int pos, int val){
	if (l==r){
		t[0][id] = pos+val;
		t[1][id] = val-pos;
		return;
	}
	int mid = (l+r)/2;

	if (pos<=mid) Update(id*2,l,mid, pos, val);
	else Update(id*2+1, mid+1, r, pos, val);
	t[0][id] = min(t[0][id*2], t[0][id*2+1]);
	t[1][id] = min(t[1][id*2], t[1][id*2+1]);
}

int Query(int id, int l, int r, int L, int R, int Type){
	if (r <L || R<l) return MOD;
	if (L<=l && r<=R) return t[Type][id];
	int mid = (l+r)/2;
	return min(Query(id*2,l,mid,L,R,Type), Query(id*2+1, mid+1,r,L,R,Type));
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> q;
	FOR(i,1,n) cin >> a[i];
	FOR(i,1,n){
		Update(1,1,n,i,a[i]);
	}
	FOR(i,1,q){
		int Type, u, v;
		cin >> Type;
		if (Type==1){
			cin >> u >> v;
			Update(1,1,n,u,v);
		}
		else{
			cin >> u;
			cout << min(Query(1,1,n,u,n,0)-u, Query(1,1,n,1,u,1)+u)<< "\n";
		}
	}
	return 0;
}