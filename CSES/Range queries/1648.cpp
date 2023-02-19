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

ll t[MAX*4], a[MAX];
int n, q;

void Build(int id, int l, int r){
	if (l==r){
		t[id] = a[l];
		return;
	}
	int mid = (l+r)>>1;
	Build(id*2, l, mid);
	Build(id*2+1, mid+1, r);
	t[id] = t[id*2] + t[id*2+1];
}

void Update(int id, int l, int r, int pos, int val){
	if (r==l && l==pos){
		t[id] = val;
		return;
	}
	int mid = (l+r)/2;
	if (mid < pos) Update(id*2+1,mid+1,r,pos,val);
	else Update(id*2,l,mid,pos,val);
	t[id] = t[id*2] + t[id*2+1];
}

ll Query(int id, int l, int r, int L, int R){
	if (R<l || r<L) return 0;
	if (L<=l && r<=R){
		return t[id];
	}
	int mid = (l+r)/2;
	return Query(id*2,l,mid,L,R) + Query(id*2+1, mid+1,r,L,R);
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
	Build(1,1,n);
	FOR(i,1,q){
		int q, u, v;
		cin >> q >> u >> v;
		if (q==1){
			Update(1,1,n,u,v);
		} else{
			cout << Query(1,1,n,u,v) << "\n";
		}
	}
	return 0;
}