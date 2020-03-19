#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

int strToInt(string a){
	char pre;
	int result = 0;
	int temp = 0;
	int pw = 0;
	stack <int> num;
	vector <int> ope;
	if(a[0] == '+' || a[0] == '-' || a[a.size()-1] == '+' || a[a.size()-1] == '-'){
		return -2000;
	}
	for(int i=0;i<a.size();i++){
		if(a[i] != '-' && a[i] != '+'){
			num.push(a[i] - '0');
		} else {
			if(pre == '+' || pre == '-'){
				return -2000;
			}
			while(!num.empty()){
				temp += (num.top() * pow(10, pw));
				num.pop();
				pw ++;
			}
			ope.push_back(temp);
			temp = 0;
			pw = 0;
			if(a[i] == '+') ope.push_back(-1);
			if(a[i] == '-') ope.push_back(-2);
		}
		pre = a[i];
	}
	while(!num.empty()){
		temp += (num.top() * pow(10, pw));
		num.pop();
		pw ++;
	}
	ope.push_back(temp);

	result = ope[0];
	for(int i=1;i<ope.size();i+=2){
		if(ope[i] == -1){
			result += ope[i+1];
		} else {
			result -= ope[i+1];
		}
	}
	
	return result;
}
int main(){
	int n, g;
	string a;
	int so = 0;
	cin >> n >> g;
	for(int i=0;i<n;i++){
		char temp;
		cin >> temp;
		a += temp;
	}
	
	sort(a.begin(), a.end());
	
	do{
		int b = strToInt(a);
		if(b == g){
			so ++;
			for(int i=0;i<a.size();i++){
				cout << a[i] << " ";
			}
			cout << "= " << g << endl;
		} 
	} while(next_permutation(a.begin(), a.end()));
	
	if(so == 0){
		cout << "Impossible" << endl;
	}
} 
