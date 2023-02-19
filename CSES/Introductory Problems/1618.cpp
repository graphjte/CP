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
	
	int n;
	cin >> n;
	int tmp = 1, res =0;
	for(int i=1; tmp*5<=n; i++){
		tmp*=5;
		res+= i*(n/tmp - n/(tmp*5));
	}
	cout << res;
	return 0;
}