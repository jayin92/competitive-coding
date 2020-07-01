#include <bits/stdc++.h>

using namespace std;

int main(){
	string a, b;
	getline(cin, a);
	getline(cin, b);
	
	int sa, sb;
	sa = a.size();
	sb = b.size();
	
	int cnt2 = 0;
	int ta, tb;
	ta = tb = -1;
	for(int i=0;i<sa;i++){
		if(a[i] == 'Y'){
			ta ++;
			cnt2 += i;
			cnt2 = cnt2 - ta;
		}
	}
	for(int i=0;i<sb;i++){
		if(b[i] == 'W') {
			tb++;
			cnt2 += i;
			cnt2 = cnt2 - tb;
		}
	}
	cnt2 += (ta+1) * (tb+1);
	
	int cnt1 = 0;
	ta = tb = -1;
	for(int i=0;i<sa;i++){
		if(a[i] == 'W'){
			ta ++;
			cnt1 += i;
			cnt1 = cnt1 - ta;
		}
	}
	for(int i=0;i<sb;i++){
		if(b[i] == 'Y') {
			tb++;
			cnt1 += i;
			cnt1 = cnt1 - tb;
		}
	}
	cnt1 += (ta+1) * (tb+1);
	
	cout << min(cnt1, cnt2) << endl;
}

