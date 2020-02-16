#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int res = 0;
	if(f > e){
		int s2 = min(d, min(b, c));
		res += s2 * f;
		d -= s2; b -= s2; c -= s2;
		int s1 = min(a, d);
		res += s1 * e;
	} else {
		int s1 = min(a, d);
		a -= s1;d -= s1;
		res += s1 * e;
		int s2 = min(d, min(b, c));
		res += s2 * f;
	}
	
	
	cout << res << endl;
}
