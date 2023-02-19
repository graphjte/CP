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

const int MAX = 1e6+6;
const int MOD = 1e9+7;

int n;
int cnt[27][MAX], val[MAX], res[MAX], tt[MAX];
unordered_map<string, int> HH;

int Hash(string &s){
    if (HH[s]) return HH[s];
    long long H;
    for(int i=0; i < s.size(); i++){
        H= ((H+ (1ll*(s[i]-'a')+i)%MOD)*val[i]) % MOD;
    }
    HH[s] = H;
    return H;
}

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.fi.size() > b.fi.size();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif
    
    unordered_map<int, int> f;
    cin >> n;
    srand(time(NULL));
    FOR(i,1,n+1) val[i] = rand()% MOD;
    vector<pair<string, int> > s(n+3);
    FOR(i,1,n){
        cin >> s[i].fi;
        s[i].se = i;
    }
    sort(s.begin()+1, s.begin()+n+1, cmp);

    FOR(i,1,n){
        tt[i] = Hash(s[i].fi);
        FOR(j,0,s[i].fi.size()-1){
            string tmp = "";
            FOR(k,0,j-1) tmp+= s[i].fi[k];
            tmp+= s[i].fi[j];
            FOR(k,j, s[i].fi.size()-1){
                tmp+= s[i].fi[k];
            }
            f[tt[i]] = MOD;
            f[tt[i]] = min( f[tt[i]],  f[Hash(tmp)]+1);
        }
        res[s[i].se] = f[tt[i]];
    }
    FOR(i,1,n) cout << res[i] << "\n";
    return 0;
}