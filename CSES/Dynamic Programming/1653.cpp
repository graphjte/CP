#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 22;
const int MSK = (1 << 20)+5;

ii f[MSK];
int n, a[MAX], s;

bool Bit(int Mask, int p){
	return Mask & (1 << (p-1));
}

int offBit(int Mask, int p){
	return Mask - (1 << (p-1));
}

void DP(){
	for(int i=1; i < (1 << n); i++) f[i] = ii(9999,0); 
	f[0] = ii(1,0);
	for(int Mask = 1; Mask < MSK; Mask++){
		for(int i=1; i<=n; i++){
			if (Bit(Mask,i)){
				int preMask = offBit(Mask,i);
				ii t= f[preMask];
				if (f[preMask].se + a[i] > s) t.fi++, t.se = a[i];
				else t.se += a[i];
				f[Mask] = min(f[Mask], t);
			}
		}
	}
	cout << f[(1 << n)-1].fi;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> s;
	for(int i=1; i<=n; i++) cin >> a[i];
	DP();
	return 0;
}