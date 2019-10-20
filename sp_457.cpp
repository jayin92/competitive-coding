#include <bits/stdc++.h>

using namespace std;

int main(){
	string a, b;
	cin >> a;
	cin >> b;
	if(a.size() != b.size()){
		cout << "No" << endl;
		return 0; 
	}
	for(int i=0;i<a.size();i++){
		if("A" <= a[i] && a[i] <= "Z"){
			if("A" <= b[i] && b[i] <= "Z"){
				continue;
			} else {
				cout << "No" << endl;
				return 0;
			}
		} else if("a" <= a[i] && a[i] <= "z"){
			if("a" <= b[i] && b[i] <= "z"){
				continue;
			} else {
				cout << "No" << endl;
				return 0;
			}
		} else {
			if("0" <= b[i] && b[i] <= "9"){
				continue;
			} else {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
} 
