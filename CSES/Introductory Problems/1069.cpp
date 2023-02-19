#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = -1;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	string s;
	int r=0, res=0;
	cin >> s;
	for(int i=0; i < s.size(); i++){
		if (s[i]==s[i-1]) r++;
		else r = 1;
		res = max(res, r);
	}
	cout << res;
	return 0;
}