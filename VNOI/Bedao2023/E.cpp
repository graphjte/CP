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

int n;
vector<int> a(MAX);

bool cmp(int &i, int &j) {
    cout << "compare " << i << " " << j << endl;
    char x;
    cin >> x;
    if (x == '<') return true;
    return false;
}

void quickSort(vector<int> &Data, int l , int r)
{
	// If the first index less or equal than the last index
	if (l <= r)
	{
		// Create a Key/Pivot Element
		int key = Data[(l+r)/2];

		// Create temp Variables to loop through array
		int i = l;
		int j = r;

		while (i <= j)
		{
			while (cmp(Data[i], key))
				i++;
			while (!cmp(Data[j], key))
				j--;

			if (i <= j)
			{
				swap(Data[i], Data[j]);
				i++;
				j--;
			}
		}

		// Recursion to the smaller partition in the array after sorted above

		if (l < j)
			quickSort(Data, l, j);
		if (r > i)
			quickSort(Data, i, r);
	}
}
 
int main(int argc, char const *argv[])
{
    // cin.tie(0)->sync_with_stdio(0);
    // if (fopen("input.txt", "r")){
    //     freopen("input.txt","r",stdin);
    // }
    
    cin >> n;
    FOR(i,1,n) {
        a[i] = i;
    }
    // sort(a.begin() + 1, a.end(), cmp);
    // FOR(i,1,n) {
    //     FOR(j,i+1,n) {
    //         if (!cmp(a[i], a[j])) {
    //             swap(a[i], a[j]);
    //         }
    //     }
    // }
    quickSort(a,1,n);
    int l = 1, r = n;
    int res = -1;
    while (l<=r) {
        int mid = (l+r)/2;
        // x = mid, y = mid+1 
        cout << "compare_k " << a[mid] << endl;
        char x;
        cin >> x;
        if (x=='<') {
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }    
    l = 1, r = n; 
    int rR = 0;
    while (l<=r) {
        int mid = (l+r)/2;
        // x = mid, y = mid+1 
        cout << "compare_k " << a[mid] << endl;
        char x;
        cin >> x;
        if (x=='>') {
            rR= mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    if (res >= 1 && res+1<=n) {
        if (rR-1 >=1 && rR<=n && rR-1 == res)
        cout << "answer " << a[res] << 
        " "  << a[res+1] << endl;
        return 0;
    }
        cout << "no_answer" << endl;
    return 0;
}