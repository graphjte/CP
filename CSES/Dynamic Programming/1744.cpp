#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 555;

int n, m, dp[MAX][MAX];

int Cal(int N, int M){
	if (N==M) return 0;
	if (dp[N][M]) return dp[N][M];
	dp[N][M] = 999999;
	for(int i=1; i<=N; i++){
		dp[N][M] = min(dp[N][M], 1 + Cal(i,M) + Cal(N-i, M));
	}
	for(int i=1; i<=M; i++){
		dp[N][M] = min(dp[N][M], 1 + Cal(N,i) + Cal(N, M-i));
	}
	return dp[N][M];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> m;
	cout << Cal(n, m);
	return 0;
}