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
	string a, b;
	cin >> a >> b;
	vector<long long> ans;
	long long k = a.size();
	long long n = b.size();
	const long long ck = pow_(c, k-1, M);
	long long ha = hash_(a);
	long long hb = hash_(b.substr(0, k));
	
	if(ha == hb) ans.push_back(0);
	
	for(long long i=1;i<=n-k;i++){
		hb = (hb - ((b[i-1] - 'a' + 1) * ck)) * c + ((b[i+k-1] - 'a' + 1));
		hb += M;
		hb %= M;
		if(ha == hb) ans.push_back(i);
	}
	
	long long tmp = ans.size();
	for(long long i=0;i<tmp;i++){
		cout << ans[i];
		if(i != tmp - 1) cout << " ";
		else cout << endl;
	}
	
}