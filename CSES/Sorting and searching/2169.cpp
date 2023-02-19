#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 2e5+6;
 
int n, f[2][MAX], B[MAX], B1[MAX], b[MAX];
map<ii, int> m;
ii a[MAX];
 
bool cmp(ii a, ii b){
	if (a.fi == b.fi) return a.se > b.se;
	else return a.fi < b.fi;
}
 
int Find(int x){
	return lower_bound(b+1, b+n+1, x) - b;
}
 
void Update(int x){
	x = Find(x);
	for(; x > 0; x-=x&-x) B[x]++;
}
 
void Update2(int x){
	x = Find(x);
	for(; x<MAX; x+=x&-x) B1[x]++;
}
 
int Get(int x){
	int ret = 0; x= Find(x);
	for(; x < MAX; x+=x&-x) ret+= B[x];
	return ret;
}
 
int Get2(int x){
	int ret= 0; x= Find(x);
	for(; x > 0; x-=x&-x) ret+= B1[x];
	return ret;
}
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i].fi >> a[i].se;
		m[a[i]] = i;
		b[i] = a[i].se;
	}
	sort(b+1, b+n+1);
	sort(a+1, a+n+1,cmp);
	
	int Max = 0, Min = INT_MAX;
	for(int i=1; i<=n; i++){
		f[0][m[a[i]]] = Get(a[i].se); //lon hon 
		Update(a[i].se);
	}
	for(int i=n; i >=1; i--){
		f[1][m[a[i]]] = Get2(a[i].se); //nho hon 
		Update2(a[i].se);
	}
	for(int i=1; i>=0; i--){
		for(int j=1; j<=n; j++){
			cout << f[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
