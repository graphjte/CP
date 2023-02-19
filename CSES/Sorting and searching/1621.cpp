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
	
	int n, tmp;
	set<int> s;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> tmp;
		s.insert(tmp);
	}
	cout << s.size();
	return 0;
}