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
    srand(time(NULL));
    int n = 3e6;
    vector<int> f(n+3);
    unordered_map<int, unordered_map<int, int> > M;
    f[0] = 1;
    FOR(i,1,n){
        if (i&1){
            f[i] = f[i/2];
        }
        else{
            f[i] = f[i/2] + f[i/2 - 1];
        }
        int u = f[i] / __gcd(f[i], f[i-1]); 
        int v = f[i-1] / __gcd(f[i], f[i-1]); 
        if (u > 100 || v>100) continue;
        if (!M[v][u]) M[v][u] = i-1;
    }
    int U, V;
    while (cin >> U >> V){
            if (U==V){
                cout << 0 << "\n";
                continue;
            }
            int u = U/__gcd(U, V);
            int v = V/__gcd(U, V);
            if (u>100 || v > 100) {
                cout << -1 << "\n";
                continue;
            }
            if (!M[u][v]){
                cout << -1 << "\n";
                continue;
            }
            else {
                cout << M[u][v] << "\n";
            }
    }
    // FOR(i,1,30){
    //     int a = rand()%R + 1;
    //     int b = rand()%R + 1;
    //     FOR(i,1,n){
    //         if (f[i]*b == f[i+1]*a){
    //             cout << a << " " << b << " " << i << "\n";
    //             break;
    //         }
    //     }
    // }
    return 0;
}