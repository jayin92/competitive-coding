#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int tmp[2];
	cin >> tmp[n%2];
	bool flag = 1;
	
	while(--n){
		cin >> tmp[n%2];
		if(tmp[0] != tmp[1]){
			flag = false;
		}
	}
	if(flag)
	cout << "Yes" << endl;
	else 
	cout << "No" << endl;
}
