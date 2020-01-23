#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int bomb[101][101];
    int cot[101][101];
    int n, m;
    cin >> n >> m;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            cot[i][j] = 0;
            bomb[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> bomb[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i-1>=0 && j-1>=0 && bomb[i-1][j-1] == 1){
            	cot[i][j] ++;
			}
            if(i-1>=0 && bomb[i-1][j] == 1){
            	cot[i][j] ++;
			}
            if(i-1>=0 && j+1<m && bomb[i-1][j+1] == 1){
            	cot[i][j] ++;
			}
            if(j+1<m && bomb[i][j+1] == 1){
            	cot[i][j] ++;
			}
            if(i+1<n && j+1<m && bomb[i+1][j+1] == 1){
            	cot[i][j] ++;
			}
            if(i+1<n && bomb[i+1][j] == 1){
            	cot[i][j] ++;
			}
            if(i+1<n && j-1 >= 0 && bomb[i+1][j-1] == 1){
            	cot[i][j] ++;
			}
            if(j-1>=0 && bomb[i][j-1] == 1){
            	cot[i][j] ++;
			}
        }
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<m-1;j++){
    		cout << cot[i][j] << " ";
		}
		cout << cot[i][m-1] << endl;
	}
}
