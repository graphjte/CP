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
        vector<int> a(n+1);
        FOR(i,1,n) {
            cin >> a[i-1];
        }
        sort(a.begin(), a.end(), greater<int>());
        if (a[k-1] > a[k]) {
            cout << a[k] +1 << "\n";
        }
        else if (a[k-1] + 1 <= a[0]) {
            cout << a[k-1] + 1 << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
    return 0;
}