#include <iostream>
#include <string>
using namespace std;

int main(){
	string guess = "1234";
	string a;
	int A, B; 
	bool flag = 1;
	while(1){
		A = B = 0;
		cout << endl << "guess: ";
		cin >> a;
		if(a == guess) break;
		for(int i=0;i<4;i++){
			if(a[i] == guess[i]) A++;
			else if(guess.find(a[i]) != string::npos) B++;
		}
		cout << endl << A << "A" << B << "B";
	}
	
	cout << "You guess right!" << endl;
} 
