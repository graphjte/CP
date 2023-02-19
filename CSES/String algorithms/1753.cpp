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

const int MAX = 1e6+6;
const int MOD = 1e9+7;
const ll MM = (MOD*MOD);
const int Base = 30;

int res, H[MAX], T, P[MAX];
string s, t;


int32_t main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif

    cin >> s; s= ' ' + s;
    cin >> t; t= ' ' + t;

    P[0] = 1;
    FOR(i,1,s.size()-1){
        H[i] = (1ll*H[i-1]*Base + (s[i]-'a'+1)) % MOD;
        P[i] = P[i-1]*Base;
        P[i]%= MOD;
    }
    FOR(i,1,t.size()-1){
        T = (1ll*T*Base + (t[i]-'a'+1)) % MOD;
    }
    FOR(i,1,s.size()){
        int j = i + t.size()-2;
        if (j > s.size()) break;
        int tmp =  (H[j] - H[i-1]*P[j-i+1]+MM)%MOD;
        if (tmp == T) res++; 
    }
    cout << res;
    return 0;
}