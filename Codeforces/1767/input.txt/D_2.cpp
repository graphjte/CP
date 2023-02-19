#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 2e5+6;
const int MOD = 1e9+7;

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    int n = 4;
    string s = "11";
    vector<int> a(n); 
    FOR(i,0,n-1) a[i] = i + 1;
    vector<int> can_win(n+1);
    int cc = 0;
    while (next_permutation(a.begin(), a.end())) {
        cc++;
        vector<int> players = a, winners;
        int round = 0;
        while (players.size() > 1) {
            for(int i = 0; i < players.size(); i+=2) {
                if (s[round] == '1') {
                    winners.push_back(max(players[i], players[i+1]));
                }
                else  
                    winners.push_back(min(players[i], players[i+1]));
            }
            round++;
            winners.swap(players);
            winners.clear();
        }
        can_win[players[0]] = true;
        // if (cc > 1000000) break;
    }
    for(int i = 1; i <=n; ++i) if (can_win[i]) cout << i << " ";
    return 0;
}