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

ll DP(vector<int> &a, int pos, bool Match){
    int r = 15;
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif

    FOR(i,0,9) Map[(char)('0'+i)] = i;
    Map['a'] = Map['A'] = 10;
    Map['b'] = Map['B'] = 11;
    Map['c'] = Map['C'] = 12;
    Map['d'] = Map['D'] = 13;
    Map['e'] = Map['E'] = 14;
    Map['f'] = Map['F'] = 15;

    cin >> A >> B;
    for (auto c: A){
        L.push_back(Map[c]);
    }
    for(auto c: B){
        R.push_back(Map[c]);
    }
    RR  = DP(L, 0, 1);
    return 0;
}