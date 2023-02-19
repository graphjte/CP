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
    
    int T = 1;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n+3);
        int s = 0;
        for(int i=k; i<=n; i+=k) {
            a[i] = ++s;
        }
        int t = n+1;
        for(int i=1; i<=n; i+=k) {
            a[i] = --t;
        }
        int g = s;
        FOR(i,1,n) {
            if (a[i]) continue;
            else g++, a[i] = g;
        }
        FOR(i,1,n) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}