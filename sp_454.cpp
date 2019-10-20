/* Matrix Multiply by jayinnn
   Sprout Online Judge Problem ... 454 */


#include <bits/stdc++.h> 

using namespace std;

int main(){
	int a[11][11];
	int b[11][11];
	int result[11][11];
	
	int a_row, a_col, b_row, b_col;
	
	cin >> a_row >> a_col;
	cin >> b_row >> b_col;
	
	for(int i=0;i<11;i++){
		for(int j=0;j<11;j++){
			result[i][j] = 0;
		}
	}
	
	for(int i=0;i<a_row;i++){
		for(int j=0;j<a_col;j++){
			cin >> a[i][j];
		}
	}
	for(int i=0;i<b_row;i++){
		for(int j=0;j<b_col;j++){
			cin >> b[i][j];
		}
	}
	
	for(int i=0;i<a_row;i++){
		for(int j=0;j<b_col;j++){
			for(int k=0;k<a_col;k++){
				result[i][j] += (a[i][k] * b[k][j]);
			
			}
		}		
	}
	for(int i=0;i<a_row;i++){
		for(int j=0;j<b_col-1;j++){
			cout << result[i][j] << " "; 
		}
		cout << result[i][b_col-1] << endl;
	}
 

	
}
