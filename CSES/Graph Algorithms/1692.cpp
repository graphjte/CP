#include <bits/stdc++.h>
#define int long long
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

int n, m;

bool getBit(int x, int k){
    return 1ll & (x >> k);
}

bool Check(int val){
    string str;
    FOR(i,0,m-1){
        str.push_back(('0'+getBit(val,i)));
    }
    // cout << str << "\n";
    FOR(i,0,(1ll<<n)-1){
        string str2;
        FOR(j,0,n-1){
            str2.push_back(('0' + getBit(i,j)));
        }
        if (str.find(str2) == std::string::npos){
            return false;
        }
    }
    return true;
}

int32_t main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> n;
    m = 1ll<<n;
    m+= n-1;
    // cout << (1<<m)-1 << "\n";
    // return 0;
    FOR(i,1,(1ll<<m)-1){
        if (Check(i)){
            FOR(j,0,m-1){
                cout << getBit(i,j);
            }
            cout << "\n";
        }
    }
    return 0;
}