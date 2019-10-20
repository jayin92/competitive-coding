/* Spiral Matrix by jayinnn
   Sprout Online Judge Problem 999 */

#include <bits/stdc++.h>

using namespace std;

int main(){
	int arr[100][100];
	
	int n;
	cin >> n;
	
	int m = n;
	int temp = n;
	
	int layer = 0;
	while(m > 0){
		layer++;
		m -= 2;
	}
	int biase = 0;
	for(int i=0;i<layer;i++){
		int x = i;
		int y = i;
		while(x<=n+i-1){
			arr[x][y] = x+1-i+biase;
			x++;
		}
		x --;
		y ++; 
		while(y <= n+i-1){
			arr[x][y] = y + n + biase - i;
			y++;
		}
		x--;
		y--;

		while(x >= i){
			arr[x][y] = 2*(n-1)+1+n-1-x+i+biase;
			x--;
		}
		x++;
		y--;

		while(y>=1+i){
			arr[x][y] = 3*(n-1)+1+(n-y-1+i)+biase;
			y--;
		}

		
		biase += 4*(n-1);
		n -= 2;			
	}
	for(int i=0;i<temp;i++){
		for(int j=0;j<temp-1;j++){
			cout << arr[j][i] << " ";
		}
		cout << arr[temp-1][i] << endl;
	}
	
	
}
