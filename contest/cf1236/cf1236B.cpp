#define MOD 1000000007
#define ll long long int
#include <bits/stdc++.h>

using namespace std;

int c(int n, int k){
    unsigned long long ans = 1;
    for(int i=k;i<=n;i++){
        ans *= i;
    }
    for(int i=1;i<=k;i++){
        ans /= i;
    }

    return ans;
}

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
    unsigned long long m, n;
    cin >> n >> m;
    unsigned long long ans;
    ans = power(2, m, MOD) - 1;
    ans = power(ans, n, MOD);
    cout << ans << endl;
}