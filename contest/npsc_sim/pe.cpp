#include <bits/stdc++.h>

using namespace std;

int main(){
	string guo13[13] = {"1m", "9m", "1p", "9p", "1s", "9s", "1z", "2z", "3z", "4z", "5z", "6z", "7z"};
	string guo12[13] = {"9m", "9m", "9p", "1s", "9s", "1z", "2z", "3z", "4z", "5z", "6z", "7z", "1p"};
	string non[13] =   {"8s", "3m", "4m", "5m", "6m", "7m", "8m", "7p", "2p", "3p", "4p", "5p", "6p"};
	int n, k;
	int tmp = 0;
	cin >> n >> k;
	if(k == 13){
		do{
			for(int i=0;i<13;i++){
				cout << guo13[i]; 
				if(i != 12) cout << " ";
			}
			cout << endl;
			n--;
			tmp ++;
		} while(next_permutation(guo13, guo13 + 13) && n != 0);
	}
	else if(k == 1){
		do{
			for(int i=0;i<13;i++){
				cout << guo12[i];
				if(i != 12) cout << " "; 
			}
			cout << endl;
			n--;
			tmp ++;
		} while(next_permutation(guo12, guo12 + 13) && n != 0);
	}
	else if(k == 0){
		do{
			for(int i=0;i<13;i++){
				cout << non[i];
				if(i != 12) cout << " ";				 
			}
			cout << endl;
			n--;
			tmp ++;
		} while(next_permutation(non, non + 13) && n != 0);
	}
}

