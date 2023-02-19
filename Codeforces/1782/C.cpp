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

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        vector<int> cnt(n+1);
        for(auto &c: s) cnt[c-'a']++;
        int nGreater = 0, nLess = 0;
        for(int k = 1; k<=n; k++) {
            if (n % k != 0) continue;
            if (26 * k > n) continue;
            vector<int> curCnt(cnt.begin(), cnt.end());
            vector<int> notInS, Less;
            FOR(i,0,n-1) {
                if (curCnt[s[i]] > k) {
                    curCnt[s[i]]--;
                    if (Less.empty()) {
                        if (notInS.empty()) break;
                        Less = notInS;
                    }
                    curCnt[Less.back()]++;
                    if (curCnt[Less.back()]==k) Less.pop_back();
                }
            }
            if (Less.size() && cnt[Less.back()]!= 0) {
                FOR(i,0,n-1) {
                    if (curCnt[s[i]] < k) {
                        int pos = Less.size() - 1;
                        if (s[i] == Less.back()) {
                            pos = Less.size() -2;
                        }
                        int p = s[i]-'a';
                        if (curCnt[])
                        curCnt[s[i]]--;
                        curCnt[Less[pos]]++;
                    }
                }
            }
        }
    }
    return 0;
}