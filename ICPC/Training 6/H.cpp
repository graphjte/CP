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

const int MAX = 2e3+6;
const int MOD = 1e9+7;

int dx[] = {1,1,0, -1,-1,0};
int dy[] = {1,0,-1,-1,0,1};

int n, T, color[MAX][MAX], Color[1000000], Id[MAX][MAX], L;

bool hasNeighbor(int u, int v){
	for(int i=0; i <6; i++){
		int x = u + dx[i];
		int y = v + dy[i]; 
		if (color[x][y] && Id[x][y]<L) return true;
	}
	return false;
}

void Pre(){
	vector<ii> cnt(7,ii(0,0));
	for(int i=1; i<=5; i++) cnt[i].se = i;
	int u = 500, v = 500;
	int nextU, nextV;
	for(int i=2; i<=7; i++){
		bool Ok = false;
		for(int j=0; j<6; j++){
			int x = u + dx[j];
			int y = v + dy[j]; 
			if (hasNeighbor(x, y) && !color[x][y]){
				nextU = x; 
				nextV = y;
				Ok = true;
			}
		}
		if (!Ok){
			nextU = u + 1;
			nextV = v + 1;
			L = i;
		}
		sort(cnt.begin()+1, cnt.begin()+6);
		for(int i=1; i<6; i++){
			cout << cnt[i].fi << " ";
		}
		cout << "\n";
		for(int i=1; i<6; i++){
			cout << cnt[i].se << " ";
		}
		cout << "\n";
		cout << "VL " << u << " " << v << "\n";
		for(int j=1; j<6; j++){
			bool bad = false;
			for(int k=0; k<6; k++){
				int x = u + dx[k];
				int y = v + dy[k];
				if (cnt[j].se == color[x][y]) bad = true; 
				if (i==7) cout << "FLFLK " << color[x][y] << "\n";
			} 
			if (bad) continue;
			Color[i-1] = cnt[j].se;
			color[u][v] = cnt[j].se; 
			Id[u][v] = i-1;
			for(int k=1; k<6; k++){
				if (cnt[k].se == color[u][v]) cnt[k].fi++;
			}
			break;
		} //
		u = nextU;
		v = nextV;

	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	Pre();
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		// cout << Color[n] << "\n";

	}
	for(int i=1; i<=20; i++) cout << Color[i] << "\n";
	return 0;
}