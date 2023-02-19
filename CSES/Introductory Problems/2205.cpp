#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = -1;

	int n;

void Print(int mask){
	for(int i=n-1; i>=0 ;i--){
		cout <<  ((mask & (1 << i)) >> i);
	}
	cout << "\n";
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif

	
	cin >> n;
	for(int i=0 ; i < 1 << n; i++){
		Print((i ^ (i >> 1)));
	}
	return 0;
}