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

const int MAX = 2000+6;
const int MOD = 1e9+7;

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

int n, m, Start, End, cnt;
int f[MAX][MAX], c[MAX][MAX], tr[MAX], maxFlow, Check[MAX];
vector<string> s;

void BFS(int u){
	queue<int> q;
	q.push(u);
	while (!q.empty()){
		int u = q.front(); q.pop();
		// cout << u <<" " << End << "\n";
		if (u==End) return;
		FOR(v, 0, End){
			if (!tr[v] && f[u][v] < c[u][v]){
				tr[v] = u;
				q.push(v);
			}
		}
	}
}

void DFS(int u){
	if (u==End) return;
	FOR(v, 0, End){
		if (!tr[v] && f[u][v] < c[u][v]){
			tr[v] = u;
			DFS(v);
		}
	}
}
 
bool findPath(){
	fill(tr, tr+End+2, 0);
	tr[Start] = -1;
	BFS(Start);
	// cout << tr[End] << "\n";
	return tr[End];
}
 
void pushFlow(){
	// cout << "Hehe";
	int v = End;
	while (v!=Start){
		int u = tr[v];
		f[u][v]++;
		// cout << u << " " << v << "\n";
		f[v][u]--;
		v = u;
	}
	maxFlow++;
}

void Clear(){
	// memset(f,0,sizeof f);
	// memset(c,0,sizeof c);
	FOR(i,1,End){
		FOR(j,1,End){
			f[i][j] = c[i][j] = 0;
		}
		Check[i] = false;
	}
	maxFlow = 0;
	s.clear();
}

bool Ok(int x, int y){
	return x<=n && y<=m && x>=0 && y>=0;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	bool Cont = true;
	while (1){
		Clear();
			Cont = false;
			string tmp;
			while (getline(cin,tmp)){
				if (tmp=="") {
					Cont = true;
					break;
				}
				s.push_back(tmp);
			}
		// }
		n = s.size()-1;
		m = s[0].size()-1;
		Start = (n+1)*(m+1)+(n+1)*(m+1)+1;
		End = (n+1)*(m+1)+(n+1)*(m+1)+2;

	
		FOR(i,0,n){
			FOR(j,0,m){
				if (s[i][j]=='W'){
					int In = ((m+1)*i+j);
					c[Start][In] = 1;
					int Out = (n+1)*(m+1) + In;
					c[In][Out] = 1;
					FOR(k,0,3){
						int x = i + dx[k], y = j + dy[k];
						if (!Ok(x,y)) continue; 
						if (s[x][y]=='I') {
							int In_ij = (m+1)*i+j;
							int Out_ij = (n+1)*(m+1) + In_ij;
							c[In_ij][Out_ij] = 1;
							c[Out_ij][(m+1)*x+y] = 1;
							Check[(m+1)*x+y] = true;
						}
					}
				}
			}
		}
		FOR(i,0,n){
			FOR(j,0,m){
				if (s[i][j]=='I'){
					FOR(k,0,3){
						int x = i + dx[k], y = j + dy[k];
						if (!Ok(x,y)) continue; 
						if (!Check[(m+1)*i+j]) continue;
						if (s[x][y]=='N') {
							int In = (m+1)*i+j;
							int Out = In + (n+1)*(m+1);
							c[In][Out] = 1;
							c[Out][(m+1)*x+y] = 1;
							c[(m+1)*x+y][(m+1)*x+y + (n+1)*(m+1)] = 1;
							c[(m+1)*x+y + (n+1)*(m+1)][End] = 1;
						}
					}
				}

			}
		}
		while (findPath()) pushFlow();
		cout << maxFlow << "\n";
		// cout << "xong";
		cnt++;
		if (cnt>3) return 0;
		if (!Cont) return 0;
	}	
	return 0;
}