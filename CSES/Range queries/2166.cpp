#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define ll long long
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
#define int long long
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e18;

int t[MAX*4], Lazy[MAX*4], n, q, Q, s[MAX], a[MAX];

void Down(int id){
	if (!Lazy[id]) return;
	t[id*2]+= Lazy[id];
	t[id*2+1]+= Lazy[id];
	Lazy[id*2]+= Lazy[id];
	Lazy[id*2+1] += Lazy[id];
	Lazy[id] = 0; 
}

void Update(int id, int l, int r, int L, int R, int val){
	if (r<L || R<l) return;
	if (L<=l && r<=R){
		t[id] += val;
		Lazy[id]+= val;
		return;
	}
	int mid = (l+r)/2;
	Down(id);
	Update(id*2, l, mid, L, R, val);
	Update(id*2+1, mid+1, r, L, R, val);
	t[id] = max(t[id*2], t[id*2+1]);
}

int Query(int id, int l, int r, int L, int R){
	if (r<L || R<l) return -MOD;
	if (L<=l && r<=R){
		return t[id];
	}
	int mid = (l+r)/2;
	Down(id);
	return max(Query(id*2,l,mid,L,R), Query(id*2+1, mid+1, r, L,R));
}

void Build(int id, int l, int r){
	if (l==r){
		t[id] = s[r];
		return;
	}
	int mid = (l+r)/2;
	Build(id*2, l, mid);
	Build(id*2+1, mid+1, r);
	t[id] = max(t[id*2], t[id*2+1]);
}

int32_t main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> q;
	FOR(i,1,n) cin >> a[i],s[i]=s[i-1] + a[i];
	Build(1,0,n);
	FOR(i,1,q){
		int u, v, t;
		cin >> t >> u >> v;
		if (t==1){
			Update(1,0,n,u, n, v-a[u]);
			a[u] = v;
		} else{
			cout << max(0ll,Query(1,0,n,u,v) - Query(1,0,n,u-1,u-1))  << "\n";
		}
	}
	return 0;
}