#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main(){
	int n;
	cin >> n;
	string a[105][3];
	int data[105];
	int result_arr[8] = {0};
	for(int i=0;i<n;i++){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		if(a[i][1] == "A"){
			a[i][1] = "1";
		} else if(a[i][1] == "J"){
			a[i][1] = "11"; 
		} else if(a[i][1] == "Q"){
			a[i][1] = "12";
		} else if(a[i][1] == "K"){
			a[i][1] = "13";
		}
		
		if(a[i][2] == "club"){
			a[i][2] = "1";
		} else if(a[i][2] == "diamond"){
			a[i][2] = "2";
		} else if(a[i][2] == "heart"){
			a[i][2] = "3";
		} else {
			a[i][2] = "4";
		}
	}
	for(int i=0;i<n;i++){
		if(a[i][0] == "A"){
			data[i] = ((stoi(a[i][2])+2)*(stoi(a[i][1])+4)) % 8;
		} else if(a[i][0] == "B"){
			data[i] = ((stoi(a[i][2])+1)*(stoi(a[i][1])+7)) % 8;
		} else {
			data[i] = ((stoi(a[i][2])+3)*(stoi(a[i][1])+3)) % 8;
		}
	}
	for(int i=0;i<n;i++){
		result_arr[data[i]]++; 
	}
	int all = 0;
	for(int i=0;i<8;i++){
		if(result_arr[i] >= 2){
			all += (result_arr[i]) * (result_arr[i]-1);
		}
	}
	cout << setprecision(2) << (double)all / (double)(n*(n-1)) << endl;
} 
