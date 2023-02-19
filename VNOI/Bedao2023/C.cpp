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
    
    ll n, k;
    cin >> n >> k;
    vector<ii> a(n);
    FOR(i,1,n) {
        cin >> a[i-1].fi;
    }
    FOR(i,1,n) {
        cin >> a[i-1].se;
        a[i-1].se%=3;
    }
    sort(a.begin(), a.end());
    vector<vector<ll> > d(3);
    ll sum = 0, cnt = 0, rem = 0;
    vector<ll> Next(3);
    FOR(i,0,n-1) {
        if (a[i].fi + sum <= k) {
            sum+= a[i].fi;
            d[a[i].se] .push_back(a[i].fi);
            rem+= a[i].se;
            rem%=3;
            cnt++;
        }
        else {
            if (!Next[a[i].se]) {
                Next[a[i].se] = a[i].fi;
            }
        }
    }
    if (!rem) {
        cout << cnt;
        return 0;
    }
    FOR(to_sub,0,2) {
        int to_add = (3+to_sub-rem) %3;
        if (d[to_sub].size() && Next[to_add]) {
            if (sum - d[to_sub].back() + Next[to_add]) {
                cout << cnt;
                return 0;
            }
        }
    }
    if (!d[1].size() && rem==1) {
        if (Next[0]) {
            if (sum + Next[0] - d[2][d[2].size()-2] - d[2].back() <= k) {
                cout << cnt - 1 << "\n";
            }
        }
        else cout << cnt - 2 << "\n";
        return 0;
    }
    if (!d[2].size() && rem==2) {
        if (Next[0]) {
            if (sum + Next[0] - d[1][d[1].size()-2] - d[1].back() <= k) {
                cout << cnt - 1 << "\n";
            }
        }
        else cout << cnt - 2 << "\n";
        return 0;
    }
    cout << cnt - 1;
    return 0;
}