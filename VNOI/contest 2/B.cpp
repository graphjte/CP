#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define ll long long
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e9+7;

double polygonArea(double X[], double Y[], int n)
{
    double area = 0.0;
 
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;  
    }
    return abs(area / 2.0);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif
    int T;
    int n;
    while (cin >> n){
    // cin >> n;
    if (!n) return 0;
    double *X = new double[n];
    double *Y = new double[n];
    FOR(i,0,n-1){
        cin >> X[i] >> Y[i];
    }
    cout << setprecision(2) << fixed << polygonArea(X,Y,n);
    cout << "\n";
        delete[] X;
        delete[] Y;
    }
    return 0;
}