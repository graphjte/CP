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

const int MAX = 2e5+6;
const int MOD = 1e9+7;

ll Lazy[4*MAX], t[4*MAX], cnt[4*MAX];
ll n, q, a[MAX];

void Down(int id, int l, int r){
	// cerr << id << " " << l << " " << r << " " << Lazy[id] << "\n";
	int mid = (l+r)/2;
	int pL = (Lazy[id]);
	int pM = (Lazy[id] + cnt[id]*(mid-l));
	int pM1 =(Lazy[id] + cnt[id]*(mid+1-l));
	int pR = (Lazy[id] + cnt[id]*(r-l));
	t[id*2]+= (pM + pL)*(mid-l+1)/2;
	t[id*2+1] += (pR + pM1)*(r-mid)/2;

	Lazy[id*2]+= Lazy[id];
	Lazy[id*2+1]+= Lazy[id];
	cnt[id*2]+= cnt[id];
	cnt[id*2+1]+= cnt[id];

	Lazy[id] = 0;
	cnt[id] = 0;
}

int Query(int id, int l, int r, int L, int R){
	if (R<l || r<L) return 0;
	// cerr << "Id " << id << " " << l << " " << r << " " << t[id] << "\n";
	if (L<=l && r<=R){
		return t[id];
	}
	Down(id,l,r);
	int mid = (l+r)/2;
	return Query(id*2,l,mid,L,R) + Query(id*2+1, mid+1,r,L,R);
}

void Update(int id, int l, int r, int L, int R){
	if (R<l || r<L) return;
	if (L<=l && r<=R){
		t[id]+= (r+l-2*L +2)*(r-l+1)/2;
		Lazy[id]+= l-L+1;
		cnt[id]++;
		return;
	}
	Down(id,l,r);
	int mid = (l+r)/2;
	Update(id*2,l,mid,L,R);
	Update(id*2+1,mid+1,r,L,R);
	t[id] = t[id*2] + t[id*2+1];
}

void Build(int id, int l, int r){
	if (l==r){
		t[id] = a[l];
		return;
	}
	int mid  = (l+r)/2;
	Build(id*2, l, mid);
	Build(id*2+1, mid+1, r);
	t[id] = t[id*2] + t[id*2+1];
}

int32_t main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> q;
	FOR(i,1,n){
		cin >> a[i];
	}
	Build(1,1,n);
	FOR(i,1,q){
		int Type, u, v;
		cin >> Type >> u >> v;
		if (Type==1){
			// cerr<< "Update " << u << " " << v << "\n";
			Update(1,1,n,u,v);
		}
		else{
			// cerr << "Query " << u << " " << v << "\n";
			cout << Query(1,1,n,u,v) << "\n";
		}
	}
	return 0;
}