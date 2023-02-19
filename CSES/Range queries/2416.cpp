#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first.first
#define se first.second
#define pos second
#define Data pair<ii, int> 
#define pb push_back
#define all(x) x.begin(),x.end()
#define ll long long
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e9+7;

ll s[MAX], res[MAX], Sum=0;
ll Lazy[MAX*4], t[MAX*4];
int n, a[MAX],Q;
pair<ii, int> q[MAX];
deque<int> dq;

void Down(int id, ll l, ll r){
	if (Lazy[id]==0) return; 
	ll mid = (l+r)/2;
	t[id*2]+= (mid-l+1)*Lazy[id];
	t[id*2+1]+= (r-mid)*Lazy[id];
	Lazy[id*2]+= Lazy[id];
	Lazy[id*2+1]+= Lazy[id];
	Lazy[id] = 0;
}

void Update(int id, int l, int r, int L, int R, ll k){
	if (R<l || r<L) return;
	if (L<=l && r<=R){
		t[id]+= k*(r-l+1);
		Lazy[id] += k;
		return;
  	}
  	Down(id,l,r);
  	int mid = (l+r)/2;
  	Update(id*2, l, mid, L,R,k);
  	Update(id*2+1, mid+1,r,L,R,k);
  	t[id] = t[id*2] + t[id*2+1];
}

ll Query(int id, int l, int r, int L, int R){
	if (R<l || r<L) return 0;
	if (L<=l && r<=R){
		return t[id];
	}
	Down(id,l,r);
	int mid = (l+r)/2;
	return Query(id*2,l,mid,L,R) + Query(id*2+1, mid+1,r,L,R);
}

void Push(int i){
	while (!dq.empty() && a[dq.front()] < a[i]){
		int tmp = dq.front();
		dq.pop_front();
		// Sum-= a[tmp] * (dq.front() - tmp);
		Update(1,1,n,tmp, dq.front()-1, -a[tmp]);
		// cout << "Pop " << tmp << " "<< Sum << "\n";
	}
	// Sum+= (dq.front() - i)*a[i];
	// cout << "Push " << i<< " "<< Sum  << "\n";
	Update(1,1,n,i,dq.front()-1,a[i]);
	dq.push_front(i); // R?
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> Q;
	FOR(i,1,n){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	a[n+1] = INT_MAX;
	FOR(i,1,Q){
		int u, v;
		cin >> u >> v;
		q[i] = pair<ii,int>(ii(u,v),i);
	}
	sort(q+1, q+Q+1, greater<Data>());

	int p = 1;
	dq.push_front(1+n);
	FORD(i,n,1){
		Push(i);
		while (q[p].fi == i){
			res[q[p].pos] = Query(1,1,n,i,q[p].se) - (s[q[p].se] - s[i-1]);
			// cout << i << " " << Query(1,1,n,i,q[p].se) << "\n";
			p++;
		}
	}

	FOR(i,1,Q){
		cout << res[i] << "\n";
	}
	return 0;
}