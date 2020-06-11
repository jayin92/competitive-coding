#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
	int n;
	int test;
	double result = 0;
	cin >> n;
	long cord[n][2];
	vector <double> dis;
	for(int i=0;i<n;i++){
		cin >> cord[i][0] >> cord[i][1];
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			dis.push_back((double)sqrt((double)pow(cord[i][0]-cord[j][0],2)+(double)pow(cord[i][1]-cord[j][1],2)));
		}
	}
	
	for(int i=0;i<dis.size();i++){
		result += dis[i];
	}
	
	double sum = result*((double)6/(n*(n-1)));
	printf("%f\n", sum);
}


