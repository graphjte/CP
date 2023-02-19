#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAXN = 4e5+6;
const int SQRTN = 1400;
const int MOD = 1e9+7;

ll M;
vector<ll> conv;

void calcConvolution() {
    int n = SQRTN - 1;
    vector<ll> f(n+1);
    f[0] = 1;
    FOR(i,1,n) {
        FOR(j,i,n) {
            f[j]+= f[j-i];
            f[j] %= M;
        }
    }

    conv = f;

    FOR(i,2,4) {
        int n = conv.size() - 1;
        int m = f.size() - 1;
        vector<ll> newConv(n + m + 1);
        FOR(j,0,n) {
            FOR(k,0,j) {
                if (j - k <= m) {
                    newConv[j] += 1ll * conv[k] * f[j - k];
                    newConv[j] %= M;
                }
            }
        }
        swap(conv, newConv);
        newConv.clear();
    }
}

void solve1(int n) {
    int y = sqrt(n);
    y+= (y*y < n);
    int x = (n/y) + ((n%y) > 0);
    vector<vector<char> > ans;
    int nBlocks = 0;
    FOR(i,1,x) {
        ans.push_back(vector<char>(y));
        FOR(j,1,y) {
            if (nBlocks < n) ans[i-1][j-1] = '#';
            else ans[i-1][j-1] = '.';
            nBlocks++;
        }
    }
    cout << ans.size() << " " << ans[0].size() << "\n";
    for(auto &u: ans) {
        for(auto &v: u) {
            cout << v;
        }
        cout << "\n";
    }
}

void solve2(int n) {
    int y = sqrt(n);
    y+= (y*y < n);
    int x = (n/y) + ((n%y) > 0);

    ll ans = 0;
    swap(x, y);
    int minPerimeter = 2*(x+y);
    while (x * y >= n && x >= y) {
        ans+= conv[x*y - n] * (1 + (x != y));
        ans%= M;
        minPerimeter = min(minPerimeter, 2*(x + y));
        x++; y--;
    }
    cout << minPerimeter << " " << ans << "\n";
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }

    int t, u;
    cin >> t >> u;
    if (u==2) {
        cin >> M;
        calcConvolution();
    }
    while (t--) {
        int n;
        cin >> n;
        if (u&1) solve1(n);
        else solve2(n);
    }
    return 0;
}