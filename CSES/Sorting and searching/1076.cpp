#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, k, a[MAX];

void Solve(){
	int m = (k+1)/2, nLeft= 0;
	priority_queue<ii> Left;
	priority_queue<ii, vector<ii>, greater<ii> > Right;

	for(int i=1; i<=n; i++){
		while (!Left.empty() && Left.top().se <= i - k) Left.pop();
		while (!Right.empty() && Right.top().se <= i - k) Right.pop();

		if (nLeft < m){
			Right.push(ii(a[i],i));
			Left.push(Right.top()); Right.pop();
			nLeft++;
		}
		else{
			Left.push(ii(a[i],i));
			Right.push(Left.top()); Left.pop();
		}

		while (!Left.empty() && Left.top().se <= i - k) Left.pop();

		if (i < k) continue;
		cout << Left.top().fi << " ";
		if (a[i-k+1] <= Left.top().fi) nLeft--;

	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	Solve();
 	return 0;
}