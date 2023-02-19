#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define ll long long
#define FOR(i,a,b) for (int i=a; i<=b; ++i)
#define FORD(i,b,a) for (int i=b; i>=a; --i)
using namespace std;

const int MAX = 2e6+6;
const int MOD = 1e9+7;
const int M = 1e9+7;
const ll MM = M*M;
const int Base = 29;

int Id[MAX], pos[MAX], cnt=0, T, Match[MAX], New[MAX], cnt2;
string ret;
map<int, int> Map; 
string s;
int Op[MAX], Cl[MAX], nextBracket[MAX];

ll P[MAX], H[MAX];

int Hash(int l, int r){
    return (1ll*H[r] - 1ll*H[l-1]*P[r-l+1] + MM) % M;
}

void decomp(int l, int r){
	if (Op[r] == Op[l-1] && Cl[r]== Cl[l-1]){
		Id[l]=++cnt;
		pos[cnt] = l;
		if (Map[Hash(l,r)]) {
			Match[cnt] = Map[Hash(l,r)];
			ret+= to_string(New[Match[Id[l]]]);
		}
		else {
			Map[Hash(l,r)] = cnt;
			cnt2++;
			New[Id[l]] = cnt2;
			ret+= s.substr(l, r-l+1);
		}
		return;
	}
	Id[l] = ++cnt;
	pos[cnt] = l;

	if (Map[Hash(l,r)]) {
		Match[cnt] = Map[Hash(l,r)];
		ret+= to_string(New[Match[Id[l]]]);
		return;
	}
	else {
		Map[Hash(l,r)] = cnt;
		ret += s.substr(l, nextBracket[l]-l)+"(";
	}
	cnt2++;
	New[Id[l]] = cnt2;


	bool rem = false, checked = true;
	int prev = nextBracket[l]+1, tmp = 0;
	for(int i=nextBracket[l]+1; i<=r; i++){
		if (s[i]=='(') tmp++;
		if (s[i]==')') tmp--;
		if (rem){
			if (!checked){
				checked = true;
			} 
			else{
				decomp(prev, i-2);
				ret+= ",";
			}
			prev = i;
			rem = false;
		}
		if (s[i]==',' && !tmp){
			rem= true;
		} 
	}
	decomp(prev,r-1);
		ret+=")";
}


void Init(){
	for(int i=1; i<=s.size(); i++){
		pos[i] = Id[i] = New[i] = Match[i] = 0;
		Op[i] = Cl[i] = 0;
		nextBracket[i] = 0;
	}
	Map.clear();
	ret = "";
	cnt = cnt2= 0;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	    freopen("input.txt","r",stdin);
	#endif

	cin >> T;
	while (T--){
		Init();
		cin >> s;
		s=  ' ' + s;
		P[0] = 1;
		for(int i=1; i<s.size(); i++){
            H[i] = (1ll*H[i-1]*Base + (s[i]-'a'+1)) % M;
            P[i] = (1ll*P[i-1]*Base) % M;
		}
		// cout << s << "\n";
		for(int i=1; i<s.size(); i++){
			Op[i] = Op[i-1] + (s[i]=='(');
			Cl[i] = Cl[i-1] + (s[i]==')');
		}
		for(int i=s.size()-1; i>0; i--){
			if (s[i]=='(') nextBracket[i] = i;
			else nextBracket[i] = nextBracket[i+1];
		}
		cnt = 0;
		decomp(1, s.size()-1);	
		cnt = 0;
		cout << ret << "\n";
	}
	// cout << Match[3] << "\n";
	return 0;
}