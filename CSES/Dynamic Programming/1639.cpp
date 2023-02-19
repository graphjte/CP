#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 5006;

int n, m, f[MAX][MAX];
string s, t;

int DP(int i, int j){
	if (i==0) return j;
	if (j==0) return i;
	if (f[i][j]) return f[i][j];
	if (s[i]==t[j]) {
		f[i][j] = DP(i-1,j-1);
		return f[i][j];
	}
	f[i][j] = min({DP(i-1,j-1), DP(i-1,j), DP(i,j-1)}) + 1;
	return f[i][j];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	getline(cin,s);
	getline(cin,t);
	n = s.size(); m = t.size();
	s= ' ' + s;
	t= ' ' + t;

	cout << DP(n,m);
	return 0;
}