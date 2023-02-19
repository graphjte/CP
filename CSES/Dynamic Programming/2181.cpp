#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 1005;
const int MSK = 1 << 10;
const int MOD = 1e9+7;

int f[MAX][MSK], n, m;

bool getBit(int mask ,int k){
	return mask & (1 << k);
}

void genMask(int mask, int pos, int cur, vector<int> &masks){
	if (pos > n) return;
	if (pos==n) masks.push_back(cur);
	if (getBit(mask,pos)==1){
		genMask(mask, pos+1, cur, masks);
	}
	else{
		if (pos+1 <n && !getBit(mask,pos+1)) {
			genMask(mask, pos+2, cur, masks);
		}
		genMask(mask, pos+1, cur|(1<<pos), masks);
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> m;

	f[1][0] = 1;

	int M = 1 << n;

	for(int i=2; i<=m+1; i++){
		for(int mask=0; mask < M; mask++){
			vector<int> nextMasks;
			genMask(mask,0,0, nextMasks);

			for(int Next: nextMasks){
				f[i][Next] += f[i-1][mask];
				f[i][Next] %= MOD;
			}
		}
	}
	// cout << f[2][3];
	cout << f[m+1][0];
	return 0;
}