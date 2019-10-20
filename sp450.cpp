/* Escape from the Daughter Red by jayinnn
   Sprout Online Judge ... Problem 450 */
   
#include <bits/stdc++.h>

using namespace std; 

int main(){
	string ori;
	cin >> ori;
	int x = 0;
	int y = 0;
	int temp = 0;
	bool comma = 0;
	for(int i=ori.size()-2;i>=1;i--){
		if(ori[i] == ','){
			comma = 1;
			temp = 0;
		} else if(!comma){
			if(ori[i] == '-'){
				y *= -1;
				temp ++;
			} else {
				y += (ori[i] - '0') * pow(10,temp);
				temp ++;
			}
			
		} else {
			if(ori[i] == '-'){
				x *= -1;
				temp ++;
			} else {
				x += (ori[i] - '0') * pow(10,temp);
				temp ++;
			}			
		}
	}
	
	cout << "(" << (x+3)*2 << "," << (x+y)*2 << ")"  << endl;
}
