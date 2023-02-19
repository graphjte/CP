#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 20;

int vs[MAX][MAX];
ll res; string s;
int dx[] ={-1,0, 1,0};
int dy[] ={0 ,-1,0,1};
char m[] ={'U','L','D','R'};

bool Ok(int x, int y){
	return !vs[x][y] && x >=0 && x<7 && y>=0 && y<7;
}

void DFS(int x, int y, int step){
	if (x==6 && y==0){
		if (step == 48) res++;
		return;
	}

	if (Ok(x-1,y) && Ok(x+1,y) && !Ok(x,y-1) && !Ok(x,y+1)) return;
	if (!Ok(x-1,y) && !Ok(x+1,y) && Ok(x,y-1) && Ok(x,y+1)) return;

	vs[x][y] = true;
	
	for(int i=0; i<4; i++){
		int u = x + dx[i], v = y + dy[i];
		if (Ok(u,v) && (s[step]=='?' || (s[step]!='?' && m[i]==s[step]))){
			DFS(u,v,step+1);
		}
	}
	vs[x][y] = false;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	

	cin >> s;
	DFS(0,0,0);
	cout << res;
	return 0;
}