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

int xd[8] = {2,1,-1,-2,-2,-1,1,2};
int yd[8] = {1,2,2,1,-1,-2,-2,-1};

int f[9][9];

bool valid(int x, int y) {
    return !f[x][y] && 0 < x && x <= 8 && 0 < y && y <= 8;
}

int Cal(int x, int y) {
    int cnt = 0;
    for(int i=0;i<7; i++) {
        int X = x+xd[i], Y = y+yd[i];
        if (valid(X,Y)) cnt ++;
    }
    return cnt;
}

void Try(int x, int y, int cnt){
	if (cnt == 64){
		FOR(i,1,8){
			FOR(j,1,8){
				cout << f[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	vector<ii> r;
	FOR(i,0,7){
		int u = x + xd[i], v = y + yd[i];
		if(valid(u, v)){
			r.push_back(ii(Cal(u,v),i));
		}
	}
	sort(all(r));
	for(ii t: r){
		int i = t.se;
		f[x+xd[i]][y +yd[i]] = cnt+1;
		Try(x + xd[i], y + yd[i], cnt+1);
		f[x+xd[i]][y +yd[i]] = 0;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif
	int x, y;
	cin >> y >> x;
	f[x][y]++;
	Try(x, y,1);
	return 0;
}