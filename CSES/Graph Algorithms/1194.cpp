#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 1111;

char a[MAX][MAX];
ii Pre[MAX][MAX], st;
vector<ii> M;
map<ii, char> Map;
int n, m, vs[MAX][MAX];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

struct Data
{
	int x, y, isMonster;
	Data(int _x=0, int _y=0, int _z=0){
		x = _x;
		y = _y;
		isMonster = _z;
	}
};


ii operator -(ii a, ii b){
	return ii(a.fi - b.fi, a.se - b.se);
}

bool Ok(Data u){
	return a[u.x][u.y] == '.' && u.x>0 && u.x <=n && u.y>0 && u.y<=m ;
}

void BFS(){
	Map[ii(1,0)] = 'D';
	Map[ii(0,1)] = 'R';
	Map[ii(-1,0)]= 'U';
	Map[ii(0,-1)]= 'L';

	//add monsters first
	queue<Data> q;
	for(ii t: M) {
		q.push(Data(t.fi,t.se,1));//monsters
		vs[t.fi][t.se] = 1;
	}
	q.push(Data(st.fi,st.se,0));//player
	vs[st.fi][st.se] = 1; 
	

	while (!q.empty()){
		Data u = q.front(); q.pop();
		if (!u.isMonster && (u.x==1 || u.x==n || u.y==1 || u.y==m)){
			///Print result///
			cout << "YES" << "\n";
			vector<char> res;
			ii tmp = ii(u.x,u.y);
			while (tmp!=st){
				ii pre = Pre[tmp.fi][tmp.se];
				res.push_back(Map[tmp - pre]);
				tmp = pre;
			}
			reverse(res.begin(), res.end());
			cout << res.size() << "\n";
			for(char x: res) cout << x;
			exit(0);
			/////////////////
		}
		for(int i=0; i < 4; i++){
			Data v = Data(u.x + dx[i], u.y + dy[i], u.isMonster);
			if (Ok(v) && !vs[v.x][v.y]){
				vs[v.x][v.y] = true;
				q.push(v);
				Pre[v.x][v.y] = ii(u.x,u.y);
			}
		}
	}
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
			if (a[i][j] == 'M') M.push_back(ii(i,j));
		}
	}	
	BFS();
	cout << "NO";
	return 0;
}