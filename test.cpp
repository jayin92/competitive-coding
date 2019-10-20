#include <bits/stdc++.h>

using namespace std;

int main(){
	int n[4] = {1,2,3,4};
	for(int i=1;i<4;i++){
		*n = n+i;
	}
	for(int i=0;i<3;i++){
		cout << n+i << endl;
	}
}
