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
        if (n%2==0) {
            cout << "No\n";
            continue;
        }
        int L = (3*n+3)/2;
        int R = L + n - 1;
        int tmp = (n+1)/2;
        map<int, int> a;
        int flag = 0;
        FORD(i,R,L) {
            a[i] = tmp;
            tmp++;
            if(i > L && tmp > n) {
                flag = true;
                break;
            }
        }
        tmp = (n-1)/2;
        if (flag) FOR(i,L, R) {
            a[i] = tmp;
            tmp--;
            if (!tmp) break;
        } 
        cout << "Yes\n";
        FOR(i,L,R) {
            cout << i - a[i] << " " << a[i] << "\n";
        }
    }
    return 0;
}