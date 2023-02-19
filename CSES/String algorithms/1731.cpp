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

int f[MAX], n, cnt, isEnd[1000006], t[1000006][26];
string s;

void Add(string &s){
    int u = 0;
    for(char &c: s){
        if (t[u][c-'a']==0) t[u][c-'a'] = ++cnt;
        u = t[u][c-'a'];
    }
    isEnd[u] = true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif

    cin >> s;
    cin >> n;
    FOR(i,1,n){
        string tmp;
        cin >> tmp;
        Add(tmp);
    }
    //dp
    f[0] = 1;
    FOR(i,0,s.size()){
        int u = 0;
        FOR(j,i+1,s.size()){
            if (!t[u][s[j-1]-'a']) break;
            u = t[u][s[j-1]-'a'];
            if (isEnd[u]){
                f[j]+= f[i];
                f[j]%= MOD;
            }
        }
    }
    cout << f[s.size()];
    return 0;
}