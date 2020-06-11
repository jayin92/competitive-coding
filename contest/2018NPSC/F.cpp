#include <iostream>

using namespace std;

int main(){
	unsigned long n,m;
	
	cin >> n >> m;
	unsigned long score[m+1] = {0};
	unsigned long i=1;
	unsigned long ac_num = 0;
	bool flag = 1;
	while(flag){
		cout << i << endl << flush;
		cin >> ac_num;
		if(ac_num != 0){
			score[ac_num] += 1;
		}
		else{
			score[0] = n-i;
			flag = 0;
		}
		i++;
	}
	cout << "0" << endl;
	for(unsigned long j=0;j<m+1;j++){
		cout << score[j] << endl; 
	}
	
	return 0;
}
