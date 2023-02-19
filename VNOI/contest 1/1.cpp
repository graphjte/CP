#include <bits/stdc++.h>
// #define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define ll long long
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 2e3+6;
const int MOD = 1e9+7;

int n, m, res;
vector<int> a[MAX];
int mu[MAX];

vector< vector<int> > tmp(MAX, vector<int>(2));


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif

    mu[0] = 1;
    FOR(i,1,MAX-1){
        mu[i] = 2ll*mu[i-1];
        mu[i]%= MOD;
    }
    cin >> n >> m;
    // vector<vector<int> > a(n+3, vector<int>);
    FOR(i,1,m){
        int tmp, t2;
        cin >> tmp;
        FOR(j,1,tmp){
            cin >> t2;
            a[i].push_back(t2);
            // cout << t2 << "\n";
        }
    }
    FOR(mask,1,mu[m]-1){
        // vector< vector<int> > tmp(n+3, vector<int>(2));
        bool bad = false;
        FOR(Bit,0,m-1){
            if (mask& (1<<Bit)){
                for(auto val: a[Bit+1]){
                    int color = 0;
                    if (val < 0) color = 1;
                    // cout << mask << " " << abs(val) << "\n";
                    if (tmp[abs(val)][1-color]) bad = true;
                    tmp[abs(val)][color] = true;
                }
            }
        }
        if (!bad) {
            int cnt  = n;
            FOR(i,1,n) if (tmp[i][0] || tmp[i][1]) cnt--;
            FOR(i,1,n) FOR(j,0,1) if (tmp[i][j]) tmp[i][j] = 0;
            if (bad) continue;
            if (__builtin_popcount(mask)%2!=0) res+= mu[cnt], res%= MOD;
            else res-= mu[cnt], res = (res+ MOD)%MOD;
            // cout << mask << " " << mu[cnt] << "\n";
        }
        else             FOR(i,1,n) FOR(j,0,1) if (tmp[i][j]) tmp[i][j] = 0;
    }
    cout << (mu[n] - res + MOD)%MOD;
    return 0;
}