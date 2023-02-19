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
    
    int n;
    cin >> n;
    int N = 1 << n;
    string s;
    vector<int> bad(N+1);
    cin >> s;
    FORD(i,N,1) {
        // how many teams < p[i]
        int tmp = 0;
        FORD(round, n-1, 0) {
            if (s[round]=='1') {
                tmp = tmp*2+1;
            }
        }
        if (tmp >= i) bad[i] = true;
        // > i
        tmp = 0;
        FORD(round, n-1, 0) {
            if (s[round]=='0') {
                tmp = tmp*2+1;
            }
        }
        if (N - i < tmp) bad[i] = true;
    }
    FOR(i,1,N) if (!bad[i]) cout << i << " ";
    return 0;
}