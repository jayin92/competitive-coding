#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	n--;
	for(int i=0;i<n;i++){
		cin >> a[i]; 
	}

	if(n == 1){
		cout << 1 << endl;
		return 0; 
	}
	if(n == 2){
		if(a[0] - (a[1] - a[0]) > 0)
			cout << a[0] - (a[1] - a[0]) << endl;
		else{
			if(a[1] - a[0] > 1){
				cout << a[0] + (a[0] + a[1]) / 2 << endl;
			} else {
				cout << a[1] + (a[1] - a[0]) << endl;
			}
		}
			
		return 0;
	}
	int d = min(a[1] - a[0], a[n-1]-a[n-2]);
	for(int i=0;i<n-1;i++){
		if(a[i+1] != a[i] + d){
			cout << a[i] + d << endl; 
		}
	}

	return 0;
}

