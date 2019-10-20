#include <bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	char randarr[10] = {'0','1','2','3','4','5','6','7','8','9'};	
	random_shuffle(randarr, randarr+10);	
	string ans, guess;
	for(int i=0;i<4;i++){
		ans += randarr[i]; 
	}
	cout << "The answer is:" << ans << endl;
	int a, b;
	while(1){
		a = b = 0;
		cout << "Your guess:";
		cin >> guess;
		cout << endl;
		if(ans == guess) break;
		for(int i=0;i<4;i++){
			if(guess[i] == ans[i]) a++;
			else if(ans.find(guess[i]) != string::npos) b++;
		}
		cout << a << "A" << b << "B" << endl;
	} 	
	cout << "Your guess is right!!!" << endl;	
}
