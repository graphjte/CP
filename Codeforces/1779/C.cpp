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
        vector<ll> a(n+1);
        vector<ll> b;
        ll sum = 0;
        FOR(i,1,n) {
            cin >> a[i];
            if (i <=m) b.push_back(a[i]);
        }
        int cnt = 0;
        set<ll> S;
        FOR(i,m+1, n) {
            S.insert(a[i]);
            sum+= a[i];
            while (sum < 0) {
                sum-= 2*(*S.begin());
                S.erase(S.begin());
                cnt++;
            }
        }
        // cout << cnt << "\n";
        reverse(b.begin(), b.end());
        sum = 0;
        priority_queue<ll> pq;
        for(int i=0; i <= m-2; i++) {
            sum+= b[i];
            pq.push(b[i]);
            while (sum > 0) {
                sum-= 2*pq.top();
                cnt++;
                pq.pop();
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}