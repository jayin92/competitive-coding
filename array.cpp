#include <bits/stdc++.h>

using namespace std;

int main(){
	int arr[100][100];
	
	int n, b;
	scanf("%d,%d", &n, &b);
	stringstream ss;
	if(b == 1){
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
			while(x <= n+i-1){
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
				string a;
				ss.clear();
				ss << arr[j][i];
				ss >> a;
				for(int k=0;k<(3-a.size());k++){
					cout << "0";
				}
				cout << arr[j][i] << ",";
			}
			string a;
			ss.clear();
			ss << arr[temp-1][i];
			ss >> a;
			for(int k=0;k<(3-a.size());k++){
				cout << "0";
			}
			cout << arr[temp-1][i] << endl;
		}
	}
	else if(b == 2){
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
		for(int j=0;j<temp;j++){
			for(int i=0;i<temp-1;i++){
				string a;
				ss.clear();
				ss << arr[j][i];
				ss >> a;
				for(int k=0;k<(3-a.size());k++){
					cout << "0";
				}
				cout << arr[j][i] << ",";
			}
			string a;
			ss.clear();
			ss << arr[j][temp-1];
			ss >> a;
			for(int k=0;k<(3-a.size());k++){
				cout << "0";
			}
			cout << arr[j][temp-1] << endl;
		}
	}
	
	
}
