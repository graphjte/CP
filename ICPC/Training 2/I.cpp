#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define ll long long
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
#define iii pair<int,ii>
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e9+7;

int n, A, B;
ii a[MAX];
int sum[MAX];

map <iii,int>  dp;

int Calc(int num, int A /*current point*/, int B){
	if (A<0) return 0;
	if (num > n) return 0;
	if (dp[iii(num,ii(A,B))]!=0) return dp[iii(num,ii(A,B))];
	if (A>B){
		int an = a[num].se + sum[num+1] - Calc(num+1, 150, A+a[num].fi-B+150);
		int Mn = min(A-1,B+a[num].fi);
		int khongAn = Calc(num+1,A-1-Mn+150,B+a[num].fi-Mn+150);
		return dp[iii(num,ii(A,B))] = max(an, khongAn);
	}
	else{
		int Mn = min(B, A+a[num].fi);
		int an = a[num].se + sum[num+1] - Calc(num+1, B-Mn+150, A+a[num].fi-Mn+150);
		return dp[iii(num,ii(A,B))] = an;
	}
}

int32_t main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> n >> A >> B;
	FOR(i,1,n){
		cin >> a[i].fi >> a[i].se;
	}
	FORD(i,n,1){
		sum[i] = sum[i+1] + a[i].se;
	}
	cout << Calc(1,A,B) << " " << sum[1] - Calc(1,A,B);
	return 0;
}