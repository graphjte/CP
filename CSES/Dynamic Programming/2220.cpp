#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = -1;

string a, b;
ll dp[20][15][3][3];

ll Cal(string &s, int pos, char last, bool match, bool allZero){
	if (pos==s.length()) return 1;
	if (dp[pos][last-'0'][match][allZero]!=-1) return dp[pos][last-'0'][match][allZero];

	char r = '9'; 
	if (match) r = s[pos]; 

	ll ret = 0;
	for(char c = '0'; c <= r; c++){
		if (c!=last || (allZero && c=='0')){
			ret+= Cal(s, pos+1, c, match & (c==r), allZero & c=='0');
		}
	}
	dp[pos][last-'0'][match][allZero] = ret;
	return ret;
}

bool Check(string s){
	for(int i=1; i < s.size(); i++){
		if (s[i]==s[i-1]) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> a >> b;
	memset(dp, -1, sizeof dp);
	ll R = Cal(b,0,'0',1,1);
	memset(dp, -1, sizeof dp);
	ll L = Cal(a,0,'0',1,1);
	cout << R - L + Check(a) << "\n";
	return 0;
}