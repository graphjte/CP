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

const int MAX = 1e6+6;
const int MOD = 1e9+7;

int a[MAX], b[MAX], n, q, cnt, No[MAX];
int t[MAX*10];
int c[MAX*10][2];

bool getBit(int x, int k){
	return x & (1 << k);
}

void Insert(int x){
	int u = 0;
	FORD(i,50,0){
		int Bit = getBit(x, i);
		if (!c[u][Bit]) c[u][Bit] = ++cnt;
		u = c[u][Bit];
		t[u]++;
	}
}

void Pop(int x){
	int u = 0;
	FORD(i,50,0){
		int Bit = getBit(x,i);
		u = c[u][Bit];
		t[u]--;
	}
}

int getSize(int u, int Bit){
	if (!c[u][Bit]) return 0;
	return t[c[u][Bit]];
}

int Query(int x){// <=x
	if (x<0) return 0;
	int u = 0, bad = false;
	int res = 0;
	FORD(i,50,0){
		int Bit = getBit(x,i);
		if (Bit==1){
			res += getSize(u,No[i]);
			if (!c[u][1^No[i]]) {
				bad = true;
				break;
			}
			u = c[u][1^No[i]];
		}
		else{
			if (!c[u][No[i]]) {
				bad = true;
				break;
			}
			u = c[u][No[i]];
		}
	}
	if (!bad) {
		res+= t[u];
	}
	return res;
}

int32_t main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n;
	FOR(i,1,n) {
		cin >> a[i];
		b[i] = a[i];	
		b[i]^=b[i-1];
	}
	int L = 0, R = n;

	Insert(0);
	FOR(i,1,n) Insert(b[i]);

	cin >> q;

	FOR(j,1,q){
		string tmp;
		int tt;
		cin >> tmp;
		if (tmp=="POP"){
			L++;
			FOR(i,0,50){
				if (getBit(a[L-1],i)){
					No[i] = 1^No[i];
				}
			}
			Pop(b[L-1]);
		}
		else if (tmp=="PUSH"){
			cin >> tt;
			R++;
			a[R] = tt;
			b[R] = b[R-1]^a[R];
			Insert(b[R]);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << Query(r) - Query(l-1) << "\n";
		}
	}
	return 0;
}
//14 7 11 13 12