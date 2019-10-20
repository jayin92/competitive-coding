#include <bits/stdc++.h>

using namespace std;

int main(){
	string n, t, a;
	cin >> n >> t;
	int l;
	cin >> l;
	getline(cin, a);
	for(int i=0;i<l;i++){
		getline(cin, a);
		size_t pos = a.find(t);
		
		a.insert(pos, n+" ");
		cout << a << endl;
	}
} 
