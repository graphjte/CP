#include <bits/stdc++.h>
#include <climits>
#define ll long long
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
#define ii pair<int, int>
#define fi first
#define se second
#define all(X) X.begin(), X.end()
using namespace std;

const int MAX = 1e7+3;
const int MOD = 1e9+7;

// int p[MAX];
int p[MAX][10];
int cc[MAX];
int s[MAX];

void Sieve() {
    FOR(i,1,MAX) s[i] = i;
    for(int i=2; i*i < MAX; i++) {
        if (!cc[i]) {
            for(int j = i+i; j<MAX; j+=i) {
                p[j][cc[j]] = i;
                cc[j]++;
                while (s[j] > 0 && (s[j] %i==0)) s[j]/=i;
            }
        }
        if (s[i]!=0) {
            p[i][cc[i]] = s[i];
            cc[i]++;        
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    Sieve();
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (abs(x-y) < 2) {
            cout << "-1\n";
            continue;
        }
        int tmp = abs(x-y);
        int r = INT_MAX;
        for(int i = 0; i < cc[tmp]; i++) {
            int prime = p[tmp][i];
            int res = (prime - (x%prime));
            if (res == prime) res = 0;
            r = min(r, res);
        }
        cout << r << "\n";
    }
    return 0;
}
