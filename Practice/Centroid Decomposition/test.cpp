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
    
    int n, q;
    cin >> n;
    vector<int> a(n+1);
    FOR(i,1,n) cin >> a[i];
    cin >> q;
    int L = 1, R = 0;
    int pos_max = 0;
    set<int> S[n+1];
    unordered_map<int, int> cnt;
    while (q--) {
        int l, r;
        cin >> l >> r;
        while (R < r) {
            R++;
            S[cnt[a[R]]].erase(a[R]);
            cnt[a[R]]++;
            S[cnt[a[R]]].insert(a[R]);
            if (cnt[a[R]] > pos_max) pos_max = cnt[a[R]];
        }
        while (L<l) {
            S[cnt[a[L]]].erase(a[L]);
            if (cnt[a[L]] == pos_max && S[cnt[a[L]]].empty()) pos_max--;
            cnt[a[L]]--;
            S[cnt[a[L]]].insert(a[L]);
            L++;
        }
        // cout << *S[pos_max].begin() << "\n";
        for(auto &x: S[pos_max]) cout << x << " ";
        cout << "\n";
    }
    return 0;
}