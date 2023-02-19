#include <bits/stdc++.h>
#define fi first
#define se second
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
#define ii pair<int, int>
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e9+7;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n+3), Next(n+3, n+3);
        vector<vector<int> > s(2);
        FOR(i,1,n){
            cin >> a[i];
            if (!a[i]) s[0].push_back(i);
        }
        FORD(i,n,1){
            if (a[i]) s[1].push_back(i);
        }
        int cnt = 0;
        while (s[0].size() && s[1].size() && s[0].back() > s[1].back()){
            ++cnt;
            s[0].pop_back();
            s[1].pop_back();
        }
        cout << cnt << "\n";
    }
    return 0;
}