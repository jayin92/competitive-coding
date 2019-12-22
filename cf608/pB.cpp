#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	bool a[n];
	char tmp;
	int wc, bc;
	wc = bc = 0;
	for(int i=0;i<n;i++){
		cin >> tmp;
		if(tmp == 'W'){
			wc ++;
			a[i] = 0;
		} else {
			bc ++;
			a[i] = 1; 
		}
	}
	if(wc == 0 || bc == 0){
		cout << 0 << endl;
		return 0;
	}
	int oper = 0;
	string res = "";
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n-1;j++){
			if(wc == 0 || bc == 0) break;
			if(a[j] == a[j+1]){
				oper ++;
				res += (j+1+'0');
				res += " ";
				if(a[j] == 0){
					wc -= 2;
					bc += 2;
					a[j] = a[j+1] = 1;
				} else {
					wc += 2;
					bc -= 2;
					a[j] = a[j+1] = 0;
				}
			} else {
				oper ++;
				res += (j+1+'0');
				res += " ";
				if(a[j] == 0){
					a[j] = 1;a[j+1] = 0;
				} else {
					a[j] = 0;a[j+1] = 1;
				}
			}
		}
		if((wc == 0 || bc == 0) && oper <= 3){
			cout << oper << endl;
			cout << res << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	return 0;
}

