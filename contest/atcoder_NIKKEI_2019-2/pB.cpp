#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

ll MOD = 998244353;
ll power(ll x, ll y, ll p) 
{ 
	ll res = 1; // Initialize result 

	// Update x if it is more than or 
	// equal to p 
	x = x % p; 

	while (y > 0) { 
		// If y is odd, multiply x with the result 
		if (y & 1) 
			res = (res * x) % p; 

		// y must be even now 
		y = y >> 1; // y = y/2 
		x = (x * x) % p; 
	} 
	return res; 
} 
int main(){
	int n;
	const int size = 10e3+20;	 
	int cnt[size] = {0};
	cin >> n;
	int tmp;
	unsigned long long res = 1;
	bool flag = false;
	for(int i=0;i<n;i++){
		cin >> tmp;
		if(i == 0 && tmp != 0){
			flag = true;
			continue;
		}
		if(i != 0 && tmp == 0){
			flag = true;
			continue;
		}
		cnt[tmp-1]++;
	}
	if(flag){
		cout << 0 << endl;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(cnt[i-1] == 0 || cnt[i] == 0) continue;
		res *= power(cnt[i-1], cnt[i], MOD);
		res = res % MOD;
	}
	cout << res % MOD << endl;
	
	return 0;
}

