#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
#define vvi vector< vector<char> > 
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e9+7;

int n, m, k;
vector< vvi> S;
vector<ii> res;


bool cmp(vvi &a, vvi &b) {
    for(int i=1; i < n; i++) {
        for(int j=1; j < m; j++) {
            if (a[i][j]!=b[i][j]) {
                int aa = 1, bb=1;
                FOR(x,-1,1) {
                    FOR(y,-1,1) {
                        if (!x ^ !y) {
                            if (a[i][j] != a[i+x][j+y]) aa =false;
                            if (b[i][j] != b[i+x][j+y]) bb =false;
                        }
                    }
                }
                // if (a[i][j]==a[i-1][j]) return false;
                if (aa) return false;
                if (bb) return true;
                return true;
            }
        }
    }
    return true;
}

void Process(vvi &a, vvi &b) {
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if (a[i][j]!=b[i][j]) {
                // cout << 1 << " " << i << " " << j << "\n";
                res.push_back({i+1,j+1});
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> n >> m >> k;
    FOR(K, 0, k)
    {
        vvi a(n+1, vector<char>(m+1,0));
        FOR(i, 1, n)
        {
            FOR(j, 1, m)
            {
                cin >> a[i-1][j-1];
            }
        }
        a[n][m] = K+1;
        S.push_back(a);
    }
    if(S.size() > 1) sort(S.begin(), S.end(), cmp);
    // cout << S.size();
    for(int i = 1; i < S.size(); i++) {
        Process(S[i-1], S[i]);
        // cout << 2 << "\n";
        res.push_back({0,S[i][n][m]});
    }
    cout << (int)S[0][n][m] << "\n";
    cout << res.size() << "\n";
    for(auto &tmp: res) {
        if (!tmp.first) {
            cout << 2 << " ";
            cout << tmp.second << "\n";
        }
        else cout << 1 << " "<< tmp.fi << " " << tmp.se << "\n";
    }
    return 0;
}