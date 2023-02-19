#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 1005;

int n, m,vs[MAX][MAX];
ii st, en;
char a[MAX][MAX];
ii Pre[MAX][MAX];
map<ii, char> M;
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

vector<char> d;

ii operator - (ii a, ii b){
	ii c = ii(a.fi - b.fi, a.se - b.se);
	return c;
}

void Trace(ii t){
	if (t==st) return;
	Trace(Pre[t.fi][t.se]);
	d.push_back(M[t - Pre[t.fi][t.se]]);
}

bool Ok(ii u){
	return u.fi > 0 && u.fi <=n && u.se > 0 && u.se <=m 
			&& !vs[u.fi][u.se] && a[u.fi][u.se] != '#';
}

void BFS(){
	queue<ii> q;
	q.push(st);
	vs[st.fi][st.se] = true;

	while (!q.empty()){
		ii u = q.front(); q.pop();
		// cout << u.fi << " " << u.se << "\n";
		if (u==en) break;
		for(int i=0; i <4; i++){
			ii v = ii(u.fi + dx[i], u.se + dy[i]);
			if (Ok(v)){
				vs[v.fi][v.se] = true;
				q.push(v);
				Pre[v.fi][v.se] = u;
			}
		}
	}
	M[ii(1,0)] = 'D';
	M[ii(0,1)] = 'R';
	M[ii(-1,0)]= 'U';
	M[ii(0,-1)]= 'L';
	if (vs[en.fi][en.se]){
		cout << "YES\n";
		Trace(en);
		cout << d.size() << "\n";
		for(char x: d) cout << x;
	}
	else cout << "NO";
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> a[i][j];
			if (a[i][j] == 'A') st = ii(i, j);
			if (a[i][j] == 'B') en = ii(i, j);
		}
	}
	BFS();
	return 0;
}