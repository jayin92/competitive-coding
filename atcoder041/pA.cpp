#include <bits/stdc++.h>
#define ll unsigned long long 
#define pb push_back
using namespace std;

int main(){
	ll n, a, b;
	cin >> n >> a >> b;
	ll c =  b - a;
	if(c % 2 == 0) cout << c / 2 << endl;
	else{
		cout << min(a-1, n-b) + 1 + (b - a - 1) / 2;
	}
}
