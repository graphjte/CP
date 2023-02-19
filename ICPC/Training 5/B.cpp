#include <bits/stdc++.h>
using namespace std;

int n, a[25][25], Bad;

bool Ok(int u, int v){
	return (1 <= u && u<=10 && 1<=v && v<=10);
}

int main(int argc, char const *argv[])
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	for(int i=1; i<=n; i++){
		int d, l, r, c;
		cin >> d >> l >> r >> c;
		if (d==0){
			for(int i=c; i<=c+l-1; i++){
				if (!Ok(r,i)) Bad = true;
				if (a[r][i]) Bad =true;
				a[r][i] = true;
			}
		}
		else{
			for(int i=r; i<=r+l-1; i++){
				if (!Ok(i,c)) Bad = true;
				if (a[i][c]) Bad =true;
				a[i][c] = true;
			}			
		}
	}
	if (Bad) cout << "N";
	else cout << "Y";
	return 0;
}