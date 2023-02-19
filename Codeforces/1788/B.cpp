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
        int a = n/2, b = n - a;
        int tmp = b, p10 = 1, cnt = 0;
        while (tmp%10==0){
            b+= (4+cnt)*p10;
            a-= (4+cnt)*p10;
            p10*=10;
            tmp/=10;
            cnt = 1 - cnt;
        }
        cout << a << " " << b << "\n";
    }
    return 0;
}