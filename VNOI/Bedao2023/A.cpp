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

vector<int> S = {3,2,0,2};

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
        cin >> n;
        vector<int> a(n+1), Next(n+1);
        FOR(i,1,n) {
            cin >> a[i];
        }
        stack<int> st;
        int cnt = 0;
        FOR(i,1,n) {
            st.push(a[i]);
            if (st.size() >= 4) {
                vector<int> s;
                FOR(i,1,4) {
                    s.push_back(st.top());
                    st.pop();
                }
                if (s==S) cnt++;
                else {
                    while (s.size()) {
                        st.push(s.back());
                        s.pop_back();
                    }
                }
            }
        }
        if (!cnt) {
            cout << ":(\n";
        }
        else if (cnt&1) {
            cout << "Bedao\n";
        }
        else cout << "Bemai\n";
    }
    return 0;
}