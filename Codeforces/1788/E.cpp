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

class fenwick_tree
{
private:
    vector<long long> data;
    int tree_size;

public:
    fenwick_tree(int tree_size = 0)
    {
        this->tree_size = tree_size;
        data.resize(tree_size + 1, -MOD);
    }
    ~fenwick_tree() {}
    void update(int pos, long long val)
    {
        for (; pos <= tree_size; pos += pos & -pos)
            data[pos] = max(data[pos], val);
    }
    long long query(int pos)
    {
        long long ret = -MOD;
        for (; pos > 0; pos -= pos & -pos)
            ret = max(ret, data[pos]);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int T = 1;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n+1), s(n+3), s_tmp(n+3), dp(n+1);
        FOR(i,1,n) {
            cin >> a[i];
            s[i] = s[i-1] + a[i];
            s_tmp[i] = s[i];
        }
        sort(s_tmp.begin(), s_tmp.end());
        FOR(i,0,n) {
            s[i] = lower_bound(s_tmp.begin(), s_tmp.end(), s[i]) - s_tmp.begin() + 1;
        }
        fenwick_tree FT(n+4);
        FT.update(s[0], 0);
        FOR(i,1,n) {
            dp[i] = FT.query(s[i]) + i;
            dp[i] = max(dp[i], dp[i-1]);
            FT.update(s[i], dp[i] - i);
        }
        // FOR(i,1,n) cerr << dp[i] << " ";
        // cerr << endl;
        // FOR(i,1,n) cerr << s[i] << " ";
        // cerr << endl;
        // FOR(i,0,n) cerr << s_tmp[i] << " ";
        // cerr << endl;
        cout << dp[n];
        cout << ((1 == 1 && 2 < 1)? "YES\n":"NO\n");
    }
    return 0;
}