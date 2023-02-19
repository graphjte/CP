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
	int L, R, id;
	Data (int _a=0, int _b=0, int _c=0){
		this->L = _a; this->R = _b; this->id = _c;
	}
};

vector<Data> d;
int n, t[MAX], res[MAX], m, a[MAX];
map<int, int> Last;

bool operator < (Data a, Data b){
	return a.R < b.R;
}

void Update(int id, int val){
	for(; id <=n; id+=id&-id){
		t[id]+= val;
	}
}

int Query(int id){
	int ret = 0;
	for(; id>0; id-=id&-id){
		ret+= t[id];
	}
	return ret;
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
	FOR(i,1,m){
		int u, v;
		cin >> u >> v;
		d.push_back(Data(u,v,i));
	}
	sort(all(d));

	int pi = -1;
	FOR(i,1,n){
		Update(i,1);
		if (Last[a[i]]) Update(Last[a[i]],-1);
		Last[a[i]] = i;
		while (d[pi+1].R<=i && pi+1<(int)d.size()){
			pi++;
			res[d[pi].id] = Query(d[pi].R) - Query(d[pi].L-1);
		}
	}
	FOR(i,1,m){
		cout << res[i] << "\n";
	}
	return 0;
}