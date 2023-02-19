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
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1);
        FOR(i,1,n) cin >> a[i];
        FOR(i,1,n) cin >> b[i];
        vector<int> d(n+1);
        FOR(i,1,n) {
            if (a[i] <= b[i]) continue;
            d[b[i]]++;
            d[a[i]]--;
        }
        FOR(i,1,n) {
            d[i]+= d[i-1];
        }
        vector<int> ans(n+1, 1);
        FOR(k,1,n) {
            for(int pos = k; pos <=n; pos+= k) {
                ans[k]&= (d[pos]==0);
            }
        }
        cout << accumulate(ans.begin()+1, ans.end(), 0) << "\n";
        FOR(i,1,n) {
            if (ans[i]) cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}