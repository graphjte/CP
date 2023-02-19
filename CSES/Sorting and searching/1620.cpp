#include <bits/stdc++.h>
#define pb push_back
#define FOR(i, a, b) for(int i = int(a); i <= int(b); i++)
#define FORD(i, a, b) for(int i = int(a); i >= int(b); i--)
#define REP(i, r) for(int i = 0; i < r; i++)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define READFILE freopen("input.txt", "r", stdin)
#define WRITEFILE freopen("output.txt", "w", stdout);
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
 
const int MAX=2e5+6;
 
ll n;
ll p, a[MAX], Ans;
 
bool Check(ll Time)
{
	ll ret=0;
	FOR(i,1,n){
		ret+=Time/a[i];
		if (ret>=p) return true;
	}
	return false;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        // READFILE;
    #endif
    FAST;
    
 	cin >> n >> p;
 	FOR(i,1,n){
 		cin >> a[i];
 	}
 
 	ll l=0, r=1e18+6;
 	while (l<=r){
 		ll mid=(l+r)/2;
 		if (Check(mid)) Ans=mid, r=mid-1;
 		else l=mid+1;
 	}
 	cout << Ans;
    return 0;
}
