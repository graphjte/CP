#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int MAX = 2e5+6;
 
int n, l, r;
int a[MAX];
ll s[MAX];
deque<int> dq;
 
void Update(int i){
	while (!dq.empty() && dq.front() < i-r) dq.pop_front();
	while (!dq.empty() && s[dq.back()] > s[i-l]) dq.pop_back();
	dq.push_back(i-l);
}
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	ll res = LLONG_MIN;
 
	cin >> n >> l >> r;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
		if (i>=l) {
			Update(i);
			res = max(res, s[i] - s[dq.front()]);
		}
	}
	cout << res;
	return 0;
}
