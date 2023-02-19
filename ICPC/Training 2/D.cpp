#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
using ld = long double;
using _ld = pair<ld,ld>;
int d,n,b;
vector <_ld> a;
ld ans = 1e17, one = 1.0;
void Solve(int val)
{
	ld d = val;
	ld vx_multi_vy = one*val/2.0;
	vector <_ld> b = a;
	for(auto &i : b)
	{
		while(i.first > d) i.first -= d;
	}
	ld minn = 1e19;
	for(auto &i : b)
	{
		minn = min(minn,sqrt((i.first*i.first+i.first*d)/i.second));
	}
	ld best = sqrt(vx_multi_vy);
	if(best > minn) best = minn;
	ld best_y = vx_multi_vy/best;
	cout << d << ' ' << best << ' ' << best_y << '\n';
	ans = min(ans,sqrt(best*best + best_y*best_y));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> d >> n >> b;
	a.resize(n);
	for(auto &i : a) cin >> i.first >> i.second;
	++b;
	for(int i = 1; i <= b; ++i)
	{
		if(d%i == 0) Solve(d/i);
	}
	cout << fixed << setprecision(6) << ans;
}
