#include <iostream>

int t[100] = {};

int trib(unsigned n);



int trib(unsigned n){
	int t[100];
	
	t[0] = 0;
	t[1] = 0;
	t[2] = 1;
	
	for(int i=3;i<100;i++){
		t[i] = t[i-1]+t[i-2]+t[i-3];
	}
	return t[n];
}
int main() {
  int n;
  while (std::cin >> n) std::cout << trib(n) << std::endl;
  return 0;
}
