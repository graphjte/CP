#include <bits/stdc++.h>
using namespace std;

const int N = 200000000;
vector<int> lp(N+1);
vector<int> pr;

int main()
{
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j)
        {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i])
            {
                break;
            }
        }
    }
    cout << pr.size();
}