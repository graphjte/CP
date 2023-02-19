#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 1005;

int n, m, vs[MAX][MAX], res;
char a[MAX][MAX];

bool Ok(int x, int y){
	return x > 0 && x <=n && y>0 && y<=m;
}

void DFS(int x, int y){
	vs[x][y] = true;
	for(int i=-1; i <=1; i++)
		for(int j=-1; j<=1; j++){
			if (!i ^ !j){
				if (Ok(x + i, y + j) && !vs[i+x][j+y] && a[x+i][j+y]=='.') DFS(i+x,j+y);
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
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if (!vs[i][j] && a[i][j]=='.') {
				DFS(i,j);
				res++;
			}
		}
	}
	cout << res;
	return 0;
}