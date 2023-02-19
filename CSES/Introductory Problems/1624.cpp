#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 888;

int f[MAX];
char a[MAX][MAX];
int res = 0;

bool Ok(int x, int y){
	for(int i=1; i <x; i++){
		if (f[i]==y) return false;
		if (x-y == i - f[i]) return false;
		if (x + y == i + f[i]) return false;
	}
	return true;
}

void Try(int pos){
	if (pos == 9){
		res++;
		return;
	}
	for(int i=1; i <= 8; i++){
		if (a[pos][i]!='*' && Ok(pos,i)){
			f[pos] = i;
			Try(pos+1);
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	for(int i=1; i<=8; i++){
		for(int j=1; j<=8; j++){
			cin >> a[i][j];
		}
	}

	Try(1);
	cout << res;
	return 0;
}