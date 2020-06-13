#include <bits/stdc++.h>
#define ll long long
using namespace std;

const long long c = 26;
const long long M = 1e9+7;

ll pow_(ll x, ll y, ll p) 
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


long long hash_(string s){
//	cout << s << endl;
	long long tmp = 0;
	long long n = s.size();
	for(long long i=0;i<n;i++){
		tmp += (s[i] - 'a' + 1) * (pow_(c, n-i-1, M));
		tmp += M;
		tmp %= M;
	}
	
	return tmp % M;
}


int main(){
	int n, m_;
	cin >> n >> m_;
	map<int, int> m;
	string tmp;
	for(int i=0;i<n;i++){
		cin >> tmp;
		m[hash_(tmp)] ++;
	}
	
	for(int i=0;i<m_;i++){
		cin >> tmp;
		cout << m[hash_(tmp)] << endl;
	}
	
}
