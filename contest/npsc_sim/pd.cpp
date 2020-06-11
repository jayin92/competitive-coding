#include <bits/stdc++.h>

using namespace std;

int main(){
	string a;
	int high = 1001;
	int low = 1;
	int guess = 500;
	while(true){
		guess = (high + low) / 2;
		cout << guess << endl;
		cout << flush; 
		cin >> a;
		if(a == "higher"){
			low = guess;
		} else if(a == "lower"){
			high = guess;
		} else if(a == "correct"){
			exit(0);
		}
	}

}

