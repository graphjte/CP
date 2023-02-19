#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 1e6+7;

int dp[MAX], n;

vector<int> getDigits(int s){
	vector<int> ret;
	while (s > 0){
		ret.push_back(s%10);
		s/=10;
	}
	return ret;
}

int Cal(int s){
	if (s==0) return 0;
	if (dp[s]>0) return dp[s];

	int ret = INT_MAX;
	vector<int> digits = getDigits(s);
	for(int x: digits){
		if (s>=x && x!=0) ret = min(ret, 1 + Cal(s - x));
	}
	dp[s] = ret;
	return ret;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	cout << Cal(n);
	return 0;
}