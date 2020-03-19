/* The Winter Storm is Coming by jayinnn
   Sprout Online Judge ... Problem 646 */

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	
	cin >> n;
	int m = n;
	n = (2*n+5)*(n+4);
	n /= 8;
	n = n-(m-7);
	n %= m;
	
	cout << "I got " << n << " dollars today!" <<  endl; 
} 
