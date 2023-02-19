#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int n;
int p[MAXN];
vector<int> g[MAXN];

void DFS(int u, int par) {
    multi<set> 
    for(auto &v: g[u]) {

    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    if (fopen("input.txt", "r")){
        freopen("input.txt","r",stdin);
    }
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int par;
        cin >> p[i+1] >> par;
        g[par].push_back(i+1);
    }

    DFS(1); 
    return 0;
}