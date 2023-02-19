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

int n, m;
int a[MAX], d[MAX][6];
ii f[MAX];

void Try(int pos){
    if (pos>n){
        bool bad = 0;
        FOR(i,1,m) {
            ii t1, t2;
            t1.fi = min(a[d[i][1]], a[d[i][2]]);
            t1.se = max(a[d[i][1]], a[d[i][2]]);
            t2.fi = min(d[i][3], d[i][4]);
            t2.se = max(d[i][4], d[i][3]);
            if (t1.fi == t2.fi && t1.se == t2.se){
                continue;
            }
            bad = true;
        }
        if (!bad){
            FOR(i,1,n){
                cout << a[i] << " ";
            }
            exit(0);
        }
        return;
    }
    bool bad = false;
    FOR(i,1,m) {
            ii t1, t2;
            t1.fi = min(a[d[i][1]], a[d[i][2]]);
            t1.se = max(a[d[i][1]], a[d[i][2]]);
            t2.fi = min(d[i][3], d[i][4]);
            t2.se = max(d[i][4], d[i][3]);
            if (t1.fi == t2.fi && t1.se == t2.se){
                continue;
            }
            bad = true;
        }
    if (bad) return;
    if (f[pos].fi == f[pos].se){
        a[pos] = f[pos].fi;
        Try(pos+1);
    }
    else{
        a[pos] = f[pos].fi;
        Try(pos+1);
        a[pos] = f[pos].se;
        Try(pos+1);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> n >> m;
    FOR(i,1,n) f[i] = {1,1};
    FOR(i,1,m){
        FOR(j,1,4) {
            cin >> d[i][j];
        }
        f[d[i][1]].fi = d[i][3];
        f[d[i][2]].se = d[i][4];
        f[d[i][2]].fi = d[i][3];
        f[d[i][1]].se = d[i][4];
    }
    Try(1);
    cout << -1;
    return 0;
}
