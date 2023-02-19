#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAXN = 2e5+6;
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
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0, tmp = -4;
        FOR(i,0,n-1) {
            cin >> a[i];
            if (a[i] == -1) {
                if (i && a[i-1] == -1) {
                    tmp = 4;
                }
                else tmp = max(tmp, 0);
            }
            sum+= a[i];
        }
        cout << sum + tmp << "\n";
    } 
    return 0;
}