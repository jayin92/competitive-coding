#include <iostream>

using namespace std;

int main(){
    int n, m;
    int prev = 0;
    int next;
    int result = 0;
    cin >> n >> m;
    int a[100] = {0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n-1;j++){
            cin >> next;
            if(next != prev){
                if(next == 1){
                    result += (n-1-j);
                } else {
                    result -= (n-1-j);
                }
            }
            prev = next;
        }
        a[result] ++;
        result = 0;
        prev = 0;
    }
	int max = a[0];
	for(int i=1;i<n;i++){
		if(max<a[i]){
			max = a[i];
		} 
	}
	for(int i=max;i>=1;i--){
		cout << "|";
		for(int j=0;j<n;j++){
			if(a[j] >= i){
				cout << "O|";
			} else {
				cout << " |";
			}
		}
		cout << endl;
	}
}
