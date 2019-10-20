#include <iostream>
#include <queue>* 
using namespace std;
/*
Using dp to solve this problem
worst case: O(n^2)
best case: O(n)

test data:
5 2
1 7 2 3 4 
3
0
2
3

*/
int main(){
	int n, k, q;
	cin >> n >> k;
	unsigned int a[n];
	unsigned int dp[n];
	
	
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	dp[0] = a[0];
	int min_index = 0;
	for(int i=0;i<k;i++){
		if(a[i] < dp[0]){
			dp[0] = a[i];
			min_index = i;
		}
	}
	
	for(int i=1;i<=n-k;i++){
		if(min_index == i-1){
			dp[i] = a[i];
			min_index = i;
			for(int j=i;j<i+k;j++){
				if(a[j] < dp[i]){
					dp[i] = a[j];
					min_index = j;
				}
			}
		} else {
			if(a[i+k-1] < dp[i-1]){
				dp[i] = a[i+k-1];
				min_index = i+k-1;
			} else {
				dp[i] = dp[i-1];
			}
		}
	} 
	
	cin >> q;
	while(q--){
		int c;
		cin >> c;
		cout << dp[c] << endl;
	}
	
}
