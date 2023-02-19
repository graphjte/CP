#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAXN = 3e5+6;
const int MOD = 1e9+7;

int n, st, en;
int a[MAXN], c[MAXN], d[MAXN], tt[MAXN];
vector<int> factors[MAXN], mul[MAXN];
int primeFactor[MAXN];

void Sieve() {
    FOR(i,2,MAXN - 1) {
        if (!primeFactor[i]) {
            for(int j = i; j < MAXN; j+= i) {
                primeFactor[j] = i;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }

    Sieve();
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    cin >> st >> en;
    FOR(i,1,n) {
        if (i!= en && tt[a[i]] && i!=st) continue;
        if (a[i] == 1) continue;
        int j = a[i];
        while (primeFactor[j]) {
            factors[a[i]].push_back(primeFactor[j]);
            mul[primeFactor[j]].push_back(i);
            j /= primeFactor[j];
        }
        tt[a[i]] = true;
    }
    queue<int> q; 
    q.push(st);
    d[a[st]] = st;
    while (q.size()) {
        int u  = q.front(); q.pop();
        if (u == en) break;
        for(int factor: factors[a[u]]) {
            if (c[factor]) continue;
            c[factor] = true;
            for(auto &v: mul[factor]) {
                if (!d[a[v]]) {
                    d[a[v]] = u;
                    q.push(v);
                }
            }
        }
    }
    if (a[en] == 1 || a[st] == 1) {
        if (en != st){
         cout << -1;
        return 0;
        }
    }
    vector<int> res;
    while (1) {
        res.push_back(en);
        int tmp = d[a[en]];
        if (!tmp || tmp == en) break;
        en = tmp;
    }
    reverse(res.begin(), res.end());
    if (!res.size() || res[0] != st) {
        cout << "-1";
        return 0;
    }
    cout << res.size() << "\n";
    for(auto &i: res) {
        cout << i << " ";
    }
    return 0;
}