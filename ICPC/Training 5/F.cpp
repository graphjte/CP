#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 2e6+6;

int main(int argc, char const *argv[])
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	string s;
	int f1= 0, f2=0, score[] = {0,0};
	int mm = true;
	cin >> s;
	int serving = 0;
	char Prev  = s[0];
	for(int i=1; i<(int)s.size(); i++){
		if (s[i]=='Q'){
			if (f1 >1 || f2 >1){
				cout << f1;
				if (f1>1) cout << " (winner)";
				cout << " - ";
				cout << f2;
				if (f2>1) cout << " (winner)";
				cout << "\n";
			}
			else{
				if (mm) cout << f1 << " " << "(" << score[0] << "*" << ") - " << f2 << " (" << score[1] << ")" << "\n";
				else    cout << f1 << " " << "(" << score[0] << ") - " << f2 << " (" << score[1] << "*" << ")" << "\n";
			}
		}
		if (Prev =='S' && f1<=1 && f2<=1){
			score[!serving]++;
			mm = false;
		} else if (Prev == 'R' && f1<=1 && f2<=1){
			score[serving]++;
			mm = true;
		}
		//check
		if (score[0]==10 || (score[0] - score[1] >= 2 && score[0] >= 5)){
			f1++;
			serving = 1;
			score[0] = score[1] = 0;
		}
		else if (score[1]==10 || (score[1] - score[0] >= 2 && score[1] >= 5)){
			f2++;
			serving = 0;
			score[0] = score[1] = 0;

		}
		if (s[i]!='Q') Prev = s[i];
	}
	return 0;
}