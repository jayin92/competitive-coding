#include <bits/stdc++.h>

using namespace std;

int main(){
	int x, y;
	int x_size, y_size;

	cin >> x >> y;
	y_size = log(y) / log(3) + 1;
	int a[y_size] = {0};
	int b[y_size] = {0};
	int sum[y_size] = {0};
	int result = 0;
	for(int i=x_size-1;i>=0;i--){
		a[i] += x % 3;
		x /= 3;
	}
	for(int i=y_size-1;i>=0;i--){
		b[i] += x % 3;
		x /= 3;
	}
	for(int i=0;i<y_size;i++){
		result += (a[i] + b[i]) % 3 *(10 ^ i);
	}
	cout << result << endl;
} 
