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
        int n, cnt = 0;
        cin >> n;
        int l = 0, r = n*n+1;
        FOR(i,1,n) {
            if (i&1) 
            FOR(j,1,n) {
                if (cnt&1) {
                    r--;
                    cout << r << " ";
                }
                else {
                    l++;
                    cout << l << " ";
                }
                cnt++;
            }
            else {
                vector<int> tmp;
            FORD(j,n,1) {
                if (cnt&1) {
                    r--;
                    // cout << r << " ";
                    tmp.push_back(r);
                }
                else {
                    l++;
                    // cout << l << " ";
                    tmp.push_back(l);
                }
                cnt++;
            }
            while (tmp.size())  cout << tmp.back() << " ", tmp.pop_back();

            }
            cout << "\n";
        }
    }
    return 0;
}