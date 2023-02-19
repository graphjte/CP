#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAXN = 2e5+6;
const int MOD = 1e9+7;

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int T = 1;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n+1), b(m+1), cnt(n+1);
        FOR(i,1,n) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        FOR(i,1,m) cin >> b[i];
        sort(b.begin() + 1, b.end(), greater<int>());
        sort(a.begin() + 1, a.end());
        priority_queue<int> pq;
        FOR(i,1,n) pq.push(cnt[i]);
        int res = 0;
        FOR(i,1,m) {
            if (!pq.size()) break;
            int tmp = pq.top(); pq.pop();
            // cerr << b[i] << tmp << "\n";
            if (tmp > b[i]) {
                res+= b[i];
                pq.push(tmp - b[i]);
            }
            else {
                res+= tmp;
            }
        }
        cout << res << "\n";
    }
    return 0;
}