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

struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum ^= l->sum;
        if (r) sum ^= r->sum;
    }
};

Vertex* build(vector<int> &a, int tl, int tr) {
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}

int get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new Vertex(new_val^v->sum);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//64-bit number generator

    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    FOR(i,1,n) {
        cin >> b[i];
        a[i] = b[i];
    } 
    sort(b.begin()+1, b.end());//b is the original a
    FOR(i,1,n) a[i] = lower_bound(b.begin()+1, b.end(), a[i]) - b.begin();

    vector<int> tmp(n+1, 0);
    vector<Vertex*> roots(n+1);
    roots[0] = build(tmp, 1, n);
    FOR(i,1,n) tmp[i] = rng();
    FOR(i,1,n) {
        roots[i] = update(roots[i-1],1,n,a[i],tmp[a[i]]);
    }
    int res = 0;
    int Q, ql, qr;
    cin >> Q;
    while (Q--) {
        cin >> ql >> qr;
        ql^= res;
        qr^= res;
        int l = 1, r = n, found = false;
        while (l<=r) {
            int mid = (l+r)/2;
            if (get_sum(roots[qr], 1, n, 1, mid)^get_sum(roots[ql-1], 1, n, 1, mid)) {
                found = true;
                r = mid-1;
                res = mid;
            }
            else l = mid+1;
        }
        res = b[res];
        if (!found) res = 0;
        cout << res << "\n";
    }
    return 0;
}