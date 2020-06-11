#include <bits/stdc++.h>
#include<string>
#include<sstream>
#include<iostream>

using namespace std;

int main(){
	stringstream ss;
	string strr;
	getline(cin,strr);
	ss <<strr; 
	string a[1000];
	int b=0;
	while(getline(ss,strr,' ')){
		a[b] = strr;
		b++;
	}
	stringstream sss;
	string strrr;
	getline(cin,strrr);
	sss <<strrr; 
	string aa[1000];
	int bb=0;
	while(getline(sss,strrr,' ')){
		aa[bb]=strrr;
		bb++;
	}
	bb=0;
	for(bb=0;bb<=b;bb++){
		cout<<stoi(a[bb])+stoi(aa[bb])<<' ';
	}
}

