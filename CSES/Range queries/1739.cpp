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

const int MAX = 1e3+6;
const int MOD = 1e9+7;

int n, m, a[MAX][MAX], t[MAX*4][MAX*4];

void BuildY(int idX, int lX, int rX, int idY, int lY, int rY){
	if (lY==rY){
		if (lX==rX){
			t[idX][idY] = a[lX][lY];
		} else{
			t[idX][idY] = (t[idX*2][idY]+ t[idX*2+1][idY]);
		}
		return;
	}

	int mid = (lY+rY)/2;
	BuildY(idX, lX, rX, idY*2, lY, mid);
	BuildY(idX, lX, rX, idY*2+1, mid+1, rY);
	t[idX][idY] = (t[idX][idY*2]+ t[idX][idY*2+1]);
}

void BuildX(int id, int l, int r){
	if (l==r){
		BuildY(id,l,r,1,1,n);
		return;
	}
	int mid = (l+r)/2;
	BuildX(id*2, l, mid);
	BuildX(id*2+1, mid+1, r);

	BuildY(id,l,r,1,1,n);
}

int QueryY(int idX, int id, int l, int r, int L, int R){
	if (r<L || R<l) return 0;
	if (L<=l && r<=R){
		return t[idX][id];
	}
	int mid = (l+r)/2;
	return QueryY(idX,id*2, l, mid, L, R)+ QueryY(idX, id*2+1, mid+1, r, L, R);
}

int Query(int id, int l, int r, int L, int R, int lY, int rY){
	if (r < L || R < l) return 0;
	if (L<=l && r <=R){
		return QueryY(id, 1, 1, n, lY, rY);
	}
	int mid = (l+r)/2;
	return Query(id*2, l, mid, L, R, lY, rY)+Query(id*2+1, mid+1, r, L, R, lY, rY);
}

void UpdateY(int idx, int id, int l, int r, int X, int Y, int val, int lx, int rx){
	if (l==r){
		if (lx == rx){
			t[idx][id] = val;
			return;
		}
		else{
			t[idx][id] = t[idx*2][id] + t[idx*2+1][id];
			return;
		}
	}
	int mid = (l+r)/2;
	if (Y<=mid) UpdateY(idx, id*2, l, mid, X, Y, val, lx, rx);
	else UpdateY(idx, id*2+1, mid+1,r,X,Y,val, lx, rx);
	t[idx][id] = t[idx][id*2] + t[idx][id*2+1];
}

void UpdateX(int id, int l, int r, int X, int Y, int val){
	if (l==r){
		UpdateY(id,1,1,n,X,Y,val,l,r);
		return;
	}
	int mid = (l+r)/2;
	if (X<=mid) UpdateX(id*2, l, mid, X, Y, val);
	else UpdateX(id*2+1, mid+1, r, X, Y, val);
	UpdateY(id,1,1,n,X,Y,val,l,r);
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> m;
	char tmp;
	FOR(i,1,n){
		FOR(j,1,n){
			cin >> tmp;
			if (tmp=='*') {
				a[i][j] = 1;
				// UpdateX(1,1,n,i,j,1);
			}
			else a[i][j] = 0;
		}
	}
	BuildX(1,1,n);
	FOR(i,1,m){
		int Type;
		cin >> Type;
		if (Type==1){
			int u, v;
			cin >> u >> v;
			a[u][v]^=1;
			UpdateX(1,1,n,u,v,a[u][v]);
		}
		else{
			int x,y,u,v;
			cin >> x >> y >> u >> v;
			cout << Query(1,1,n,x,u,y,v) << "\n";
		}
	}
	// cout << Query(1,1,n,1,1,4,4) << "\n";
	// cout << t[1][1] << "\n";
	return 0;
}