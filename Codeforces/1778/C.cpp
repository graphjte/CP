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

int getBit(int x, int k) {
    return x & (1 << k);
}

ll C2(int x) {
    if (x <= 0) return 0;
    return 1ll * x * (x-1) / 2 + x;
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int T = 1;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s, t;
        vector<int> pos(30, -1);
        int cnt = 0;
        cin >> s;
        cin >> t;
        FOR(i,0,n-1) {
            if (-1==pos[s[i]-'a']) pos[s[i]-'a'] = cnt++;
        }
        ll ans = 0;
        FOR(mask,0,(1 << cnt) -1 ) {
            if (__builtin_popcount(mask) > k) continue;
            int Prev = 0;
            ll curAns = 0;
            FOR(i,0,n-1) {
                if (getBit(mask, pos[s[i] - 'a'])) continue;
                else if (s[i] != t[i]) {
                    curAns += max(0ll, C2(i-1 - Prev + 1));
                    Prev = i+1;
                }
            }
            if (Prev != n) curAns += C2(n-1 - Prev + 1);
            ans = max(ans, curAns);
        }
        cout << ans << "\n";
    }
    return 0;
}