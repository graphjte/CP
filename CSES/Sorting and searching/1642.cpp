#include <bits/stdc++.h>
#define ii pair<ll, ll>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 3000;

int n;
ii a[MAX];
long long End[MAX], s;
vector<pair<ll, ii> > d;
map<long long, ii> M;


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> s;
	for(int i=1; i<=n; i++){
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a+1, a+n+1);

	for(int j=n; j>0; j--){
		for(int i=j-1; i>0; i--){
			if (M[s- a[i].fi - a[j].fi]!= ii(0,0)){
				ii tmp = M[s- a[i].fi - a[j].fi];
				cout << a[i].se <<" "<< a[j].se <<" "<<a[tmp.fi].se << " " << a[tmp.se].se << "\n"; 
				return 0;
			}
		}
		for(int k=j+1; k<=n; k++){
			M[a[j].fi + a[k].fi] = ii(j,k);
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}