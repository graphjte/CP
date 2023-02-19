// Cach 1 dung ctdl tree, cach 2 dung BIT
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
 
const int MAX = -1;
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
 
	int n, k, pos=0;
	indexed_set S;
	
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		S.insert(i);
	}
	while (n){
		int Next = (pos + k)%n;
		// cout << Next << "\n";
		cout << *S.find_by_order(Next) << " ";
		S.erase(S.find_by_order(Next));
		pos = Next;
		n--;
	}
	return 0;
}

#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 4e5+6;
 
int n,k,B[MAX];
 
void Update(int x, int k){
	for(; x < MAX; x+=x&-x) B[x]+= k;
}
 
int Get(int x){
	int ret = 0;
	for(; x>0; x-=x&-x) ret+= B[x];
	return ret;
}
 
int Next(int x, int cnt){
	int l = x, r = n*2, ret = x;
	while (l<=r){
		int mid = (l+r)/2;
		if (Get(mid) - Get(x) >= (k)%cnt+1){
			ret = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	ret = ret%n;
	if (!ret) ret+=n;
	return ret;
}
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> k;
 
	for(int i=1; i<=2*n; i++){
		Update(i,1);
	}
	int cnt = n, pos = (k%n)+1;
	while (cnt--){
		Update(pos, -1);
		Update(pos+n,-1);
		cout << pos << " ";
		if (cnt==0) return 0;
		int Nxt = Next(pos,cnt);
		pos = Nxt%n;
		if (!pos) pos = n;
	}
	return 0;
}
