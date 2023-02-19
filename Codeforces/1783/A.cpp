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
        int n;
        cin >> n; 
        vector<int> a(n+1);
        FOR(i,1,n) cin >> a[i];
        int bad = 0;
        sort(a.begin() + 1, a.end(), greater<int>());
        if (a[1] == a[2]) {
            if (a[1] == a[n]) {
                bad = 1;
            }
            else {
                bad = 2;
            }
        }
        if (bad == 1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            if (bad == 2) {
                cout << a[n] << " ";
                FOR(i,1,n-1) {
                    cout << a[i] << " ";
                }
                cout << "\n";
            }
            else {
                FOR(i,1,n) {
                    cout << a[i] << " ";
                }
                cout << "\n";
            }
        }
    } 
    return 0;
}