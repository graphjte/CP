#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = -1;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	string s;
	map<char, int> d;

	cin >> s;
	for(auto x: s){
		d[x]++;
	}
	int tmp = 0;
	char c = '0';
	for(char x = 'A'; x <= 'Z'; x++){
		if (d[x]&1) {
			tmp++;
			c = x;
		}
	}
	if (tmp > 1){
		cout << "NO SOLUTION";
		return 0;
	}
	for(char x = 'A'; x <= 'Z'; x++){
		if (x!=c){
			for(int i=1; i <= d[x]/2; i++){
				cout << x;
			}
		}
	}
	if (c!='0') for(int i=1; i<=d[c]; i++) cout << c;
		for(char x = 'Z'; x>= 'A'; x--){
		if (x!=c){
			for(int i=1; i<= d[x]/2; i++){
				cout << x;
			}
		}
	}
	return 0;
}