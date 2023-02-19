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

ll Set[4*MAX], t[4*MAX], Inc[4*MAX];
ll n, q, a[MAX];

void Down(int id, ll l, ll r){
	ll mid = (l+r)/2;
	if (Set[id]!=0){
		t[id*2] = Set[id]*(mid-l+1);
		t[id*2+1] = Set[id]*(r-mid);
		Set[id*2] = Set[id];
		Set[id*2+1] = Set[id];
		t[id*2] += Inc[id]*(mid-l+1);
		t[id*2+1] += Inc[id]*(r-mid);
		Inc[id*2] = Inc[id];
		Inc[id*2+1] = Inc[id];
	}
	else{
		t[id*2] += Inc[id]*(mid-l+1);
		t[id*2+1] += Inc[id]*(r-mid);
		Inc[id*2] += Inc[id];
		Inc[id*2+1] += Inc[id];		
	}
	Set[id] = 0;
	Inc[id] = 0;
}

ll Query(int id, int l, int r, int L, int R){
	if (R<l || r<L){
		return 0;  
	}
	if (L<=l && r<=R){
		return t[id];
	}
	Down(id,l,r);
	int mid = (l+r)/2;
	return Query(id*2, l, mid, L, R) + Query(id*2+1, mid+1, r, L, R);
}

void Update(int id, int l, int r, int L, int R, ll k, int Type){
	if (R<l || r<L) return;
	if (L<=l && r<=R){
		if (Type==1){
			Inc[id]+= k; 
			t[id]+= k*(r-l+1);
		}
		else{
			t[id] = k*(r-l+1);
			Set[id] = k;
			Inc[id] = 0;
		}
		return;
	}
	Down(id,l,r);
	int mid = (l+r)/2;
	Update(id*2, l, mid, L, R, k, Type);
	Update(id*2+1, mid+1,r, L, R, k, Type);
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

int main(int argc, char const *argv[])
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
		int Type, u, v, c;
		cin >> Type;
		if (Type==1){
			cin >> u >> v >> c;
			Update(1,1,n,u,v,c,1);
		}
		else if (Type==2){
			cin >> u >> v >> c;
			Update(1,1,n,u,v,c,2);
		}
		else {
			cin >> u >> v;
			cout << Query(1,1,n,u,v) << "\n";
		}
	}
	return 0;
}