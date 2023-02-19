#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX = -1;

vector<string> res;
string s;

bool Check(int source, int dest){
	for(int i=source; i < dest; i++){
		if (s[i] == s[dest]) return false;
	}
	return true;
}

void Gen(int pos){
	if (pos==s.size()) {
		res.push_back(s);
		return;
	}
	Gen(pos+1);
	for(int i=pos+1; i < s.size(); i++){
		if (Check(pos,i)){
			swap(s[i], s[pos]);
			Gen(pos+1);
			swap(s[pos],s[i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	#endif
	
	cin >> s;
	Gen(0);
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for(string &s: res) cout << s << "\n";
	return 0;
}