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
    
    int n, k;
    cin >> n >> k;
    int aMax = 0;
    vector<int> a(n+1);
    FOR(i,1,n) {
        cin >> a[i];
        aMax = max(aMax, a[i]);
    }
    stack<int> st;
    vector<int> L(n+1), R(n+1);
    FOR(i,1,n) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (st.size()) L[i] = st.top()+1;
        else L[i] = 1;
        st.push(i);
    }
    while (st.size()) st.pop();
    FORD(i,n,1) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (st.size()) R[i] = st.top()-1;
        else R[i] = n;
        st.push(i);
    }
    int ans = 1;
    FOR(curDivisor, 1, aMax) {
        //for each divisor of aMax, check if we can cover all element in [1, n] using that segments
        if (aMax % curDivisor == 0) {
            bool bad = false;
            int curR = 0;
            stack<ii> st;
            st.push({0,0});
            FOR(i,1,n) {
                if (a[i] % curDivisor == 0) {
                    while (st.size() && curR+1 < L[i]) {
                        st.pop();
                        if (st.size()) curR = st.top().second;
                        else {bad = true;} 
                    }
                    st.push({i, R[i]});
                    curR = R[i];
                }
            }
            while (st.size() && st.top().second < n) st.pop();
            if (!bad && st.size() >= k+1) ans = curDivisor;
        }
    }
    cout << ans;
    return 0;
}