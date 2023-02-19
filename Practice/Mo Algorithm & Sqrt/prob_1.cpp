//https://oj.vnoi.info/problem/vnoicup22_r2_d
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define ii pair<int, int>
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 1e6+6;
const int MOD = 1e9+7;

int n, k, q, B;
vector<tuple<int, int, int> > Q;
int cnt[MAX], a[MAX];
int minCount = 0, maxCount = 0;
set<int> S[MAX];

void add(int idx) {
    if (S[cnt[a[idx]]].size()) S[cnt[a[idx]]].erase(a[idx]);
    if (S[cnt[a[idx]]].empty() && minCount >= cnt[a[idx]]) minCount = cnt[a[idx]] + 1;
    cnt[a[idx]]++;
    S[cnt[a[idx]]].insert(a[idx]);
    if (maxCount < cnt[a[idx]]) maxCount = cnt[a[idx]];
    cerr << "added" << idx << " " << cnt[a[idx]]<<"\n";
}

void remove(int idx) {
    if (S[cnt[a[idx]]].size()) S[cnt[a[idx]]].erase(a[idx]);
    if (S[cnt[a[idx]]].empty() && maxCount == cnt[a[idx]]) maxCount = cnt[a[idx]]-1;
    cnt[a[idx]]--;
    S[cnt[a[idx]]].insert(a[idx]);
    if (minCount > cnt[a[idx]]) minCount = cnt[a[idx]];
    cerr << "removed " << idx <<"\n"; 
}

int get_answer() {
    if (minCount == 0) {
        for(int i= 1; i <= 5; i++) if (S[i].size()) {
            minCount = i; 
            break;
        }
    }
    cerr << maxCount << " " << minCount <<  "\n";
    if (maxCount == minCount && minCount == k) return 0;
    // return 1;
    if (maxCount!=k) return *S[maxCount].begin();
    if (minCount!=k) return *S[minCount].begin();
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> n >> k;
    FOR(i,1,n) {
        cin >> a[i-1];
    }
    B = sqrt(n);
    if (!B) B++;
    cin >> q;
    FOR(i,1,q) {
        int u, v;
        cin >> u >> v;
        Q.push_back({u-1, v-1, i});
    }
    sort(Q.begin(), Q.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b) {
        if (get<0>(a) / B != get<0>(b) / B)
            return a < b;
        return (get<0>(a) / B & 1) ? (get<1>(a) > get<1>(b)) : (get<1>(a) < get<1>(b));
    });
    int cur_l = 0;
    int cur_r = -1;
    vector<int> answers(q+1);
    for (auto [l, r, id] : Q) {
        cerr << l << " " << r << " " << id << "\n";
        while (cur_l > l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > r) {
            remove(cur_r);
            cur_r--;
        }
        answers[id] = get_answer();
    }
    FOR(i,1,q) cout << answers[i] << "\n";
    return 0;
}