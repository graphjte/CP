#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 5005;

ll n, dp[MAX][MAX][2], a[MAX];

ll Cal(int l, int r, int player){
	if (l>r) return 0;
	if (dp[l][r][player]) return dp[l][r][player];
	if (!player) dp[l][r][player] = max(a[l] + Cal(l+1,r,1-player), a[r] + Cal(l,r-1,1-player));
	else{
		dp[l][r][player] = min(Cal(l+1,r,0), Cal(l,r-1,0));
	}
	return dp[l][r][player];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	cout << Cal(1, n, 0);
	return 0;
}