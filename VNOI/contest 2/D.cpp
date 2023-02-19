#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define ll long long
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e9+7;

int n, k, a[MAX], Q, cnt[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif
    
    cin >> n >> k;
    FOR(i,1,n) cin >> a[i];
    cin >> Q;
    while (Q--){
        int l, r;
        cin >> l >> r;
        FOR(i,l,r) {
            cnt[a[i]]++;
        }
        int bad = 0;
        FOR(i,l,r){
            if (cnt[a[i]]!=k){
                bad = a[i];
                break;
            }
        }
        FOR(i,l,r) cnt[a[i]] = 0;
        if (bad) {
            cout << bad;
        }
        else cout << 0;
        cout << "\n";
    }
    return 0;
}