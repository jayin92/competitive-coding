#include <bits/stdc++.h>

using namespace std;

int main(){
	string n;
	string t;
	string a;
	int l;
	cin >> n >> t;
	cin.clear();
	cin >> l;
//	cout << n << t << l << endl;/	getline(cin, a);
	getline(cin, a);
	for(int i=0;i<l;i++){
		getline(cin, a);
		cout << a;
	}
} 
