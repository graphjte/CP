#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 1e5+6;

int n, a[MAX];
bool f[MAX];

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
	f[0] = 1; int res=  0;
	for(int j=1; j<=n; j++){
		for(int i=MAX-1; i; i--){
			if (i >= a[j]) f[i]|= f[i-a[j]];
			if (j==n && f[i]) res++;
		}
	}
	cout << res << "\n";
	for(int i=1; i<=MAX; i++)	if (f[i]) cout << i << " ";
	return 0;
}