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

struct Data{
	ll L = 0, R =0, S=0, G = 0;
};

int n, m, a[MAX];
Data t[MAX*4];

Data Combine(Data &a, Data &b){
	Data ret;
	ret.L = max(a.L, a.S + b.L);
	ret.R = max(b.R, b.S + a.R);
	ret.G = max({a.G, b.G, a.R + b.L});
	ret.S = a.S + b.S;
	return ret;
}

void Update(int id, int l, int r, int pos, int val){
	if (r==l){
		t[id].L = max(0, val);
		t[id].R = max(0, val);
		t[id].S = val;
		t[id].G = max(0, val);
		return;
	}
	int mid = (l+r)/2;
	if (pos<=mid) Update(id*2, l, mid, pos, val);
	else Update(id*2+1, mid+1,r, pos, val);
	t[id] = Combine(t[id*2], t[id*2+1]);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> m;
	FOR(i,1,n) cin >> a[i];
	FOR(i,1,n) Update(1,1,n,i,a[i]);
	FOR(i,1,m){
		int u, v;
		cin >> u >> v;
		Update(1,1,n,u,v);
		cout << t[1].G << "\n";
	}
	return 0;
}