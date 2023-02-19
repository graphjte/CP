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
        int w, d, h, a, b, f, g;
        cin >> w >> d >> h;
        cin >> a >> b >>  f >> g;
        int minDist = min(a + f, w - a + w - f) + abs(b - g);
        minDist = min(minDist, min(b + g + abs(a - f), 2*d - b - g + abs(a - f)));
        cout << minDist + h << "\n";
    } 
    return 0;
}