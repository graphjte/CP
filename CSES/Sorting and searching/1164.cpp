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
#define iii pair< pair<int,int>, int >
using namespace std;
 
const int MAX=2e5+6;
 
int Ans, Size,n ,Pos[MAX];
std::vector<iii> a; 
 
void Solve(){
	sort(a.begin(), a.end());
	priority_queue<int, vector<int>, greater<int> > pq;
	FOR(i,1,n) pq.push(i);	
	for(iii x: a){
		Size+=x.fi.se;
		Ans=max(Ans,Size);
		if (x.fi.se==1) Pos[x.se]=pq.top(), pq.pop();
		else{
			pq.push(Pos[x.se]);
		}
	}
	cout << Ans << "\n";
	FOR(i,1,n) cout << Pos[i]<<" ";
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        // READFILE;
    #endif
    FAST;
    
 	cin >> n;
 	FOR(i,1,n){
 		int u,v;
 		cin >> u >> v;
 		a.push_back(iii(ii(u,1),i)); 
 		a.push_back(iii(ii(v+1,-1),i));
 	}
 	Solve();
    return 0;
}
