#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = -1;

void Move(int Source, int Dest, int Middle, int Size){
	if (Size == 1) {
		cout << Source << " " << Dest << "\n";
		return;
	}
	Move(Source, Middle, Dest, Size -1);
	cout << Source << " " << Dest << "\n";
	Move(Middle,Dest,Source, Size-1);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	int n;
	cin >> n;
	cout << (1 << n) -1 << "\n";
	Move(1,3,2, n);
	return 0;
}