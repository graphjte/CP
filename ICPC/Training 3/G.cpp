#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
const int N = 907;
i64 flow[N][N],mark[N],t,g,ans;
int d[N],val[N][N],n,h;
int inf = 1e9;
vector <_ii> v[N];
vector <string> a;
bool able[N];
int _x[] = {0,0,-1,1};
int _y[] = {1,-1,0,0};
bool BFS()
{
    bitset <N+1> visited;
    queue <int> Line;
    Line.push(n);
    visited[n] = true;
    d[n] = 1;
    d[1] = 0;
    while(!Line.empty())
    {
        h = Line.front();
        Line.pop();
        if(h == 1) return true;
        for(auto &i : v[h])
        {
        	if(able[i.first] == false) continue;
            if(!visited[i.first] && flow[h][i.first] < i.second)
            {
                visited[i.first] = true;
                d[i.first] = d[h] + 1;
                Line.push(i.first);
            }
        }
    }
    return false;
}
i64 Dinic(int u, i64 minn)
{
    if(u == 1) return minn;
    if(mark[u] != t) mark[u] = t;
    else return 0;
    for(_ii i : v[u])
    {
    	if(able[i.first] == false) continue;
        if(d[i.first] == d[u] + 1 && flow[u][i.first] < i.second && mark[i.first] != t)
        {
            if(i64 x = Dinic(i.first,min(minn,i.second - flow[u][i.first])))
            {
                flow[u][i.first] += x;
                flow[i.first][u] -= x;
                return x;
            }
        }
    }
    return 0;
}
void Dinic()
{
    while(BFS())
    {
        while(g = (t++,Dinic(n,inf)))
        {
            ans += g;
        }
    }
}
void Clear()
{
	memset(flow,0,sizeof(flow));
	memset(mark,0,sizeof(mark));
	memset(d,0,sizeof(d));
	memset(able,0,sizeof(able));
	memset(val,0,sizeof(val));
	for(auto &i : v) i.clear();
	t = 0;
	g = 0;
	ans = 0;
	n = 0;
	h = 0;
	able[1] = true;
}
void Make_graph()
{
	int x = a.size();
	int y = a[0].size();
	int cnt = 1;
	n = x*y+2;
	for(int i = 0; i < x; ++i)
	{
		for(int j = 0; j < y; ++j)
		{
			val[i][j] = ++cnt;
			if(a[i][j] == 'W')
			{
				v[n].push_back({val[i][j],1});
			}
			if(a[i][j] == 'N')
			{
				v[val[i][j]].push_back({1,1});
			}
		}
	}
	cnt = 1;
	for(int i = 0; i < x; ++i)
	{
		for(int j = 0; j < y; ++j)
		{
			for(int k = 0; k < 4; ++k)
			{
				int u = i + _x[k];
				int vv = j + _y[k];
				if(u >= 0 && vv >= 0 && u < x && vv < y)
				{
					if(a[i][j] == 'W' && a[u][vv] == 'I')
					{
						v[val[i][j]].push_back({val[u][vv],1});
					}
				}
				if(u >= 0 && vv >= 0 && u < x && vv < y)
				{
					if(a[i][j] == 'I' && a[u][vv] == 'N')
					{
						v[val[i][j]].push_back({val[u][vv],1});
					}
				}
			}
		}
	}
}
bool visited[N];
void Remove(int h)
{
	for(auto &i : v[h])
	{
		if(visited[i.first])
		{
			able[h] |= able[i.first];
		}
		else
		{
			visited[i.first] = true;
			Remove(i.first);
			able[h] |= able[i.first];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt","r",stdin);
	string s;
	while(getline(cin,s))
	{
		if(s == "")
		{
			Clear();
			Make_graph();
			Remove(n);
			Dinic();
			cout << ans << '\n';
			a.clear();
		}
		else a.push_back(s);
	}
	Clear();
	for(auto v: s){
		
	}
	Make_graph();
	Remove(n);
	Dinic();
	cout << ans << '\n';
}