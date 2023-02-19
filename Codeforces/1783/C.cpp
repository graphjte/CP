#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 1e5+6;
const int MAXN = 2e5+7;
const int MOD = 998244353;

int n;
int a[MAX];
int pushed[303][MAXN];
int f[303][MAXN];
int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> n; 
    FOR(i,1,n) {
        cin >> a[i];
    }
    queue<ii> q;
    f[2][a[2]+ MAX] = 1;
    q.push({2, a[2]});
    int res = 0;
    while (q.size()) {
        int pos = q.front().fi, val = q.front().se;
        q.pop();
        if (pos == n) {res+= f[pos][val + MAX], res%= MOD; continue;}
        if (!val) {
            f[pos+1][a[pos+1] + MAX]+= f[pos][val + MAX];
            f[pos+1][val + a[pos+1] + MAX] %= MOD;
            if (!pushed[pos+1][val + a[pos+1] + MAX]) {
                q.push({pos+1, val + a[pos+1]});
                pushed[pos+1][val + a[pos+1]+ MAX] = true;
            }
        }
        else {
            f[pos+1][val + a[pos+1]+ MAX] += f[pos][val+ MAX];
            f[pos+1][val + a[pos+1]+ MAX] %= MOD;
            f[pos+1][-val + a[pos+1]+ MAX] += f[pos][val+ MAX];
            f[pos+1][-val + a[pos+1]+ MAX] %= MOD;
            if (!pushed[pos+1][val + a[pos+1]+ MAX]) {
                q.push({pos+1, val + a[pos+1]});
                pushed[pos+1][val + MAX+ a[pos+1]] = true;
            }
            if (!pushed[pos+1][-val + a[pos+1]+ MAX]) {
                q.push({pos+1, -val + a[pos+1]});
                pushed[pos+1][-val + a[pos+1]+ MAX] = true;
            }
        }
    }
    cout << res;
    return 0;
}