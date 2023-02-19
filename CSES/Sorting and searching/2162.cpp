#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 2e5+6;
 
int n, Next[MAX];
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	for(int i=1; i<=n; i++){
		Next[i] = i+1;
	}
	Next[n] = 1; int cnt = 0;
	for(int i=1; cnt < n; i = Next[i]){
		cout << Next[i] << " ";
		Next[i] = Next[Next[i]]; 
		cnt++;
	}
	return 0;
}
