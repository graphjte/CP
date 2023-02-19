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

const int MAX = 3e5+6;
const int MOD = 1e9+7;

int n, q, a[MAX], Lazy[MAX*4], t[MAX*4];
string s;

void Down(int id){
	t[id*2]+= Lazy[id];
	t[id*2+1]+= Lazy[id];
	Lazy[id*2]+= Lazy[id];
	Lazy[id*2+1]+= Lazy[id];
	Lazy[id] = 0;
}
 
void Build(int id, int l, int r){
	if (l==r){
		t[id] = a[l];
		return;
	}
	int mid = (l+r)/2;
	Build(id*2, l, mid);
	Build(id*2+1, mid+1, r);
	t[id] = min(t[id*2], t[id*2+1]);
}

void Update(int id, int l, int r, int L, int R, int val){
	if (r<L || R<l) return;
	if (L<=l && r<=R){
		Lazy[id] += val;
		t[id]+= val;
		return;
	}
	Down(id);
	int mid = (l+r)/2;
	Update(id*2, l, mid, L, R, val);
	Update(id*2+1, mid+1, r, L, R, val);
	t[id] = min(t[id*2], t[id*2+1]);
}

int Query(int id, int l, int r, int L, int R){
	if (r<L || R<l) return MOD;
	if (L<=l && r<=R){
		return t[id];
	}
	Down(id);
	int mid = (l+r)/2;
	return min(Query(id*2,l,mid,L,R), Query(id*2+1,mid+1,r,L,R));
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> q;
	cin >> s;
	s= ' ' + s;
	FOR(i,1,s.size()-1){
		a[i] = a[i-1] + (s[i]=='('? 1:-1);
	}
	priority_queue<int, vector<int>, greater<int> > pq;
	FOR(i,1,n){
		if (s[i]==')') pq.push(i);
	}

	Build(1,1,n);
	FOR(i,1,q){
		int x;
		cin >> x;
		if (s[x]==')'){
			Update(1,1,n,x,n,2);
			int l = 1, r = n, pos = x;
			while (l<=r){
				int mid = (l+r)/2;
				if (Query(1,1,n,mid,n)>=2){
					pos = mid;
					r = mid-1;
				}
				else l = mid+1;
			}
			Update(1,1,n,pos,n,-2);
			s[x]='(';
			s[pos]=')';
			pq.push(pos);
			cout << pos << "\n";
		} 
		else{
			pq.push(x);
			s[x]=')';
			int pos = 0;
			while (!pq.empty()){
				int u = pq.top(); pq.pop();
				if (s[u]==')'){
					pos = u;
					break;
				} 
			}
			s[pos] = '(';
			Update(1,1,n,pos,n,2);
			Update(1,1,n,x,n,-2);
			cout << pos << "\n";
		}
	}
	return 0;
}