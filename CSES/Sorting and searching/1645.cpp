#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = 2e5+6;

int n, L[MAX], a[MAX];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	stack<int> st;
	for(int i=1; i<=n; i++){
		while (!st.empty() && a[st.top()] >= a[i]) st.pop();
		if (st.size()) L[i] = st.top();
		st.push(i);
		cout << L[i] << " ";
 	}
	return 0;
}