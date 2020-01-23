#include <iostream>

using namespace std;


int throw_egg(int n){
	if(n >= 345){
		return 0;
	}
	return 1;
}


int main(){
	initialize();
	
	long long R = 2147483648;
	long long L = 1;
	
	long long  g = int((R+L)/2);
	
	while(R-L>1){
		if(throw_egg(g)){
			L = g; 
		} else {
			R = g;
		}
		
		g = int((R+L)/2); 
	}
	
	answer(L);
}

