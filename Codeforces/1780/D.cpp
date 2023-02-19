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

int setBit(int &x, int pos, int val) {
    if (x & (1 << pos)) {
        if (!val) x-= (1 << pos);
    }
    else  {
        if (val) x+= (1 << pos);
    }
}

int main(int argc, char const *argv[])
{
    // cin.tie(0)->sync_with_stdio(0);
    // if (fopen("input.txt", "r")){
    //     freopen("input.txt","r",stdin);
    // }
    
    int T = 1;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n;
        int n1 = 0, fsb;
        int arr = 0, finalArr = 0;
        FOR(i,0,29) {
            cout << "- " << (1 << i) << endl;
            cout.flush();
            cin >> m;
            if (m >= n) {
                setBit(arr,i,0);
                n1++;
                setBit(finalArr,i,1);
            }
            else setBit(arr,i,1);
            fsb = i;
            if (m <= n1) break;
            swap(m, n);
        }
        FORD(i,fsb,0) {
            finalArr+= (1 << i);
        }
        cout << "! " <<  finalArr << endl;
            cout.flush();
    }
    return 0;
}