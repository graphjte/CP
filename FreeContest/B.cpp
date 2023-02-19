#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e9+7;

int N = 1, cnt, In[MAX], n, c[MAX];
vector<int> g[MAX];
vector<ii> Q;

void DFS(int u, int par) {
    In[u] = ++cnt;
    c[u] = 1;
    for(auto &v: g[u]) {
        if (v==par) continue;
        DFS(v, u);
        c[u] += c[v];
    }
}
int t[MAX];
int Lazy[MAX];
 
void Down(int id, int l, int r){
    if (!Lazy[id]) return;
    int mid = (l+r)/2;
    Lazy[id]--;
	t[id*2]= Lazy[id]*(mid-l+1);
	t[id*2+1]= Lazy[id]*(r-mid);
	Lazy[id*2] = Lazy[id]+1;
	Lazy[id*2+1]= Lazy[id]+1;
	Lazy[id] = 0;
}
 
void Update(int id, int l, int r, int L, int R, int val){
	if (r<L || R<l) return;
	if (L<=l && r<=R){
		t[id] = val*(r-l+1);
        Lazy[id] = val+1;
		return;
	}
	Down(id, l, r);
	int mid = (l+r)/2;
	Update(id*2, l, mid, L, R, val);
	Update(id*2+1, mid+1, r, L, R, val);
    t[id] = t[id*2] + t[id*2+1];
}
 
int Query(int id, int l, int r, int L, int R){
	if (r<L || R<l) return 0;
	if (L<=l && r<=R){
		return t[id];
	}
	Down(id, l, r);
	int mid = (l+r)/2;
    return (
	Query(id*2, l, mid, L, R) + 
	Query(id*2+1, mid+1, r, L, R));
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> n;
    FOR(i,1,n) {
        int u;
        char Type;
        cin >> Type >> u;
        if (Type=='+') {
                Q.push_back({int(Type), N});
                g[u].push_back(N);
                ++N;
        }
        else Q.push_back({(int)Type,u});
    }
    DFS(0,0);
    Update(1,1,cnt, In[0],In[0],1);
    for(auto &q: Q) {
        if (q.first==(int)'+') {
            Update(1,1,cnt,In[q.second], In[q.second],1);
        }
        else if (q.first == (int)'-') {
            Update(1,1,cnt, In[q.second], In[q.second] + c[q.second]-1,0);
        }
        else {
            cout << Query(1,1,cnt,In[q.second], In[q.second] + c[q.second] - 1) << "\n";
        }
    }
    return 0;
}