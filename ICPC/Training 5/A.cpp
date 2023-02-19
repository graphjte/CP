#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 2e6+6;

ll a[MAX], l, r, n, k, gt[MAX], c[100][100];

int M(int k, int n) {
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    if (c[n][k]) return c[n][k];
    return c[n][k] = M(k - 1, n - 1) + M(k, n - 1);
}

ll C(int n, int k){
	if (n==0){ 
		if (k==0) return 1;
		else return 0;
	}
	if (n < k) return 0;
	return M(k,n);
}

ll Calc(int num, int rem, int R){
	ll cnt = 0, res = 0;

	if (rem==0) return 1;
	for(int i=1; i<=R; i++){
		if (a[i] > num) continue; 
		if ((int)log2(a[i]) + 1 >= (int)log2(num)) {
			// continue;
			res+= Calc(num - a[i], rem-1, i-1);
		}
		else cnt++;
	}
	cout <<" VC:" << C(cnt,rem) << "\n";
	cout << cnt << " " << rem << "\n";
	return res+ C(cnt,rem);
}

int main(int argc, char const *argv[])
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> k;
	gt[0] = 1;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	cin >> l >> r;

	cout << Calc(r,k,n) -  Calc(l-1,k, n);
	cout << "\n" << C(21,13) << "\n";
	return 0;
}