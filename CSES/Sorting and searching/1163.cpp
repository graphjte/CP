#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
#define iii pair<int, ii>
using namespace std;

const int MAX = 2e5+6;

int n, M, a[MAX];
priority_queue<int> pq;
map<int,int> cnt;


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> n >> M;
	set<int> s;
	s.insert(0);
	s.insert(n);
	cnt[n]++;

	for(int i=1; i<=M; i++){
		cin >> a[i];
		s.insert(a[i]);
		auto x = s.find(a[i]);
		cnt[*(x) - *prev(x)]++;
		cnt[*next(x) - *(x)]++;
		cnt[*next(x) - *prev(x)]--;

		pq.push(*(x) - *prev(x));
		pq.push(*next(x) - *(x));

		while (!cnt[pq.top()]) pq.pop();
		cout << pq.top() << " ";
	}
	return 0;
}