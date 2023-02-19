#include <bits/stdc++.h>
#define data pair< pair<int, int>, int>
#define fi first.first
#define se first.second
#define index second
using namespace std;

const int MAX = 2e5+6;

int P[21][MAX], cnt, pow2[35], SA[MAX];
string s;

vector<data> L;

void build_suffix_array(string s){
	pow2[0] = 1;
	for(int i=1; i<25; i++){
		pow2[i] = pow2[i-1]*2;
	}
	L.resize(s.size());
	for(int i=0; i < (int)s.size(); i++){
		P[0][i] = s[i]-'A';
	}

	for(int i=1; pow2[i]<(int)s.size(); i++){
		for(int j=0; j<(int)s.size(); j++){
			L[j].index = j;
			L[j].fi = P[i-1][j];
			if (j + pow2[i-1] >= (int)s.size()) L[j].se =  -1;
			else L[j].se = P[i-1][j + pow2[i-1]];
		}
		sort(L.begin(), L.end());
		for(int j=0; j < (int)s.size(); j++){
			if (j>0 && L[j].fi == L[j-1].fi && L[j].se == L[j-1].se) {
				P[i][L[j].index] = P[i][L[j-1].index];
			}
			else P[i][L[j].index] = j;
		}
		cnt++;
	}

	for(int i = 0; i < (int)s.size(); i++){
		SA[P[cnt][i]] = i;
	}
}

int LCP(int i, int j){
	int ret = 0;
	for(int k= cnt; k >=0; k--){
		if (max(i,j) + pow2[k]-1 < (int)s.size() && P[k][i]==P[k][j]){
			ret+= pow2[k];
			i+= pow2[k];
			j+= pow2[k];
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	// freopen("input.txt","r",stdin);
	cin >> s;
	build_suffix_array(s);
	int res = 0;
	for(int i=1; i < (int)s.size(); i++){
		res = max(res, LCP(SA[i-1],SA[i]));
	}
	cout << res;
	return 0;
}