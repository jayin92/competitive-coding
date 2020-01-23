#include <bits/stdc++.h>

using namespace std;


void ring(int top, int n){
	cout << top << " " << n << endl;
	if(n == 1){
		cout << "Move ring " << top << " out" << endl;
	}
	else if(n == 2){
		cout << "Move ring " << top+1 << " out" << endl;
		cout << "Move ring " << top << " out" << endl;
	} 
	else if(n == 3){
		cout << "Move ring " << top << " out" << endl;
		cout << "Move ring " << top+2 << " out" << endl;
		cout << "Move ring " << top << " in" << endl;
		cout << "Move ring " << top+1 << " out" << endl;
		cout << "Move ring " << top << " out" << endl;
		
	}
	else {
		ring(1, n-1);
		cout << "Move ring " << n-1 << " in" << endl;
		ring(n,1);
	}
}
int main(){
	int n;
	cin >> n;
	ring(1, n);
}
