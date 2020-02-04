#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int n;
	
	cin >> n;
	ll a[n];
	ll b[n];
	ll ans[n+1];
	for(int i=0;i<n;i++){
		cin >> a[i];
		ans[i+1] = 0;
	}
	for(int i=0;i<n;i++){
		int ans_ = 0;
		for(int j=1;j<=min(i, n-i-1);j++){
			if(a[i+j] < a[i] && a[i-j] < a[i]){
				ans_ ++;
			} else {
				break;
			}
		}
//		cout << ans_ << " " << i << endl;
		for(int j=1;j<=ans_;j++){
			ans[j] ++;
		}
	}
	for(int i=1;i<=n;i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	
	 
	
} 
