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
        string s;
       cin >> n;
       cin >> s; 
       int cnt = 0;
       string res = "";
       FOR(i,1,n-1) {
        if (s[i]=='0') {
            res.push_back('+');
            cnt--;
        }
        else if (cnt&1) res.push_back('+');
        else res.push_back('-');
        cnt++;
       }
       cout << res << "\n";
    }
    return 0;
}