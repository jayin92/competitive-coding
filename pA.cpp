#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;n--;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	if(n == 1){
		if(a[0] != 1) cout << 1 << endl;
		else cout << a[0] + 1 << endl;
	} else if(n == 2){
		int d = a[1] - a[0];
		if(a[0] - d >= 1) cout << a[0] - d << endl;
		else if(d % 2 == 0) cout << a[0] + d / 2 << endl;
		else cout << a[1] + d << endl;
	} else {
		int d[n-1];
		for(int i=0;i<n-1;i++){
			d[i] = a[i+1] - a[i];
		}

		for(int i=0;i<n-1;i++){
			if(d[i+1] - d[i] != 0){
				if(d[i+1] < d[i]) cout << a[i] + d[i+1] << endl;
				else cout << a[i+1] + d[i] << endl;
				return 0;
			}
		}
		
	}
}
