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

struct Edge {
  int to, rev;
  int f, cap;
};

struct Dinic {
	int nodes, src, dest;
	// int dist[maxnodes], q[maxnodes], work[maxnodes];
	// vector<Edge> g[maxnodes];
	vector<int> dist, q, work;
	vector<vector<Edge> > g;

    Dinic(int n, int s, int t) : nodes(n), src(s), dest(t) {
        dist.resize(n);
        q.resize(n);
        work.resize(n);
        g.resize(n);
    }

	void add_edge(int s, int t, int cap){
		// cout << s << " " << t << " " << cap << "\n";
	  Edge a = {t, g[t].size(), 0, cap};
	  Edge b = {s, g[s].size(), 0, cap};
	  g[s].push_back(a);
	  g[t].push_back(b);
	}

	bool dinic_bfs() {
	  fill(dist.begin(), dist.end(), -1);
	  dist[src] = 0;
	  int qt = 0;
	  q[qt++] = src;
	  for (int qh = 0; qh < qt; qh++) {
	    int u = q[qh];
	    for (int j = 0; j < (int) g[u].size(); j++) {
	      Edge &e = g[u][j];
	      int v = e.to;
	      if (dist[v] < 0 && e.f < e.cap) {
	        dist[v] = dist[u] + 1;
	        q[qt++] = v;
	      }
	    }
	  }
	  return dist[dest] >= 0;
	}

	int dinic_dfs(int u, int f) {
	  if (u == dest)
	    return f;
	  for (int &i = work[u]; i < (int) g[u].size(); i++) {
	    Edge &e = g[u][i];
	    if (e.cap <= e.f) continue;
	    int v = e.to;
	    if (dist[v] == dist[u] + 1) {
	      int df = dinic_dfs(v, min(f, e.cap - e.f));
	      if (df > 0) {
	        e.f += df;
	        g[v][e.rev].f -= df;
	        return df;
	      }
	    }
	  }
	  return 0;
	}

	int maxFlow() {
	  int result = 0;
	  while (dinic_bfs()) {
	    fill(work.begin(), work.end(), 0);
	    while (int delta = dinic_dfs(src, INT_MAX))
	      result += delta;
	  }
	  return result;
	}
};

const int MAX = 2000+6;
const int MOD = 1e9+7;

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

int n, m, Start, End, Check[MAX];
vector<string> s;

bool Ok(int x, int y){
	return x<=n && y<=m && x>=0 && y>=0;
}

void Solve(){
	n = s.size()-1;
	m = s[0].size()-1;
	int	Start = (n+1)*(m+1)+(n+1)*(m+1)+1+1;
	int	End = (n+1)*(m+1)+(n+1)*(m+1)+2+1;
	int LK = (n+1)*(m+1);
	Dinic dinic(End+2+1, Start+1, End+1);

	//create graph
	FOR(i,0,n){
		FOR(j,0,m){
			int In_ij = (m+1)*i+j;
			int Out_ij = (m+1)*i+j + LK;
			if (s[i][j] == 'W'){
				dinic.add_edge(Start+1,In_ij+1,1);
				dinic.add_edge(In_ij+1,Out_ij+1,1);
				FOR(k,0,3){
					int x = i + dx[k], y = j + dy[k];
					if (!Ok(x,y) || s[x][y]!='I') continue; 
					dinic.add_edge(Out_ij+1,x*(m+1)+y+1,1);
					dinic.add_edge(In_ij+1,Out_ij+1,1);
					Check[x*(m+1)+y] = true;
				}
			}
			else if (s[i][j] == 'I'){
				FOR(k,0,3){
					int x = i + dx[k], y = j + dy[k];
					int In_xy = x*(m+1) + y, Out_xy = In_xy + LK;
					if (!Ok(x,y) || s[x][y]!='N') continue; 
					// if (!Check[(m+1)*i+j]) continue;					
					dinic.add_edge(In_ij+1,Out_ij+1,1);
					dinic.add_edge(Out_ij+1,In_xy+1,1);
					dinic.add_edge(In_xy+1,Out_xy+1,1);
					dinic.add_edge(Out_xy+1,End+1,1);

				}
			}
		}
	}
	cout << dinic.maxFlow() << "\n";
}

void clearGraph(){
	s.clear();
	FOR(i,0,End) Check[i] = false;
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
		//clear
		clearGraph();
		Cont = false; string tmp;
		while(getline(cin,tmp)){
			if (tmp=="") {
				Cont = true;
				break;
			}
			s.push_back(tmp);
		}
		Solve();
		if (!Cont) return 0;
	}
	return 0;
}