#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<ll, ll>
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
        ll n, k;
        cin >> n >> k;
        vector<ii> a(n+1);
        ll curPower = INT_MAX;
        FOR(i,1,n) cin >> a[i].fi;
        FOR(i,1,n) {
            cin >> a[i].se;
            curPower = min(curPower, a[i].se);
        }
        sort(a.begin() + 1, a.end());
        set<ii> S;
        FOR(i,1,n) {
            S.insert({a[i].se, i});
        } 
        ll bad = 0, totalDamage = 0;
        ll genosPower = k + curPower;
        FOR(i,1,n) {
            while ((S.begin()->se) < i) S.erase(S.begin());
            curPower = S.begin()->fi;
            genosPower-= curPower;
            // cout << curPower << "\n";

            ll l = 0, r = genosPower/curPower + 1, updated= -MOD;
            ll tmp = 0;
            while (l<=r) {
                ll mid = (l+r)/2;
                if (genosPower*mid - curPower*(mid-1)*mid/2 >= a[i].fi-totalDamage) {
                    r = mid-1;
                    updated = genosPower- curPower*(mid-1);
                    tmp = genosPower*mid - curPower*(mid-1)*mid/2;
                }
                else l = mid+1;
            }
            totalDamage+= tmp;
            genosPower = updated;
            // cout << genosPower << " " << totalDamage << "\n";
            if (updated==-MOD) bad = true;

        }
        if (!bad) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}