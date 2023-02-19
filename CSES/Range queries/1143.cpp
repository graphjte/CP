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

int t[MAX*4], a[MAX], m, n;

int Combine(int x, int y){
	if (a[x] >= a[y]) return x;
	else return y;
}

void Update(int id, int l, int r, int pos){
	if (pos==l && l==r){
		t[id] = pos;
		return;
	}
	int mid = (l+r)/2;
	if (pos<=mid) Update(id*2, l, mid, pos);
	else Update(id*2+1, mid+1, r, pos);
	t[id] = Combine(t[id*2], t[id*2+1]);
}

int Query(int id, int l, int r, int val){
	if (a[t[id]] < val) return 0;
	if (l==r){
		return t[id];
	}
	int mid = (l+r)/2;
	if (a[t[id*2]]>=val) return Query(id*2, l, mid, val);
	else return Query(id*2+1, mid+1, r, val);
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
	FOR(i,1,n) Update(1,1,n,i);
	FOR(i,1,m){
		int tmp;
		cin >> tmp;
		int t = Query(1,1,n,tmp);
		if (t){
			a[t]-= tmp;
			Update(1,1,n,t);
			cout <<t << " ";
		}
		else cout << 0 << " ";
	}
	return 0;
}