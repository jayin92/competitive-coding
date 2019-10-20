#include <bits/stdc++.h>

using namespace std;
int surround(int n, int m, int x, int y, bool path[101][101]);

int main(){
	int n, m;
	cin >> n >> m;
	bool path[101][101] = {0};
	
	for(int i=0;i<n;i++){
		string a;
		cin >> a;
		for(int j=0;j<m;j++){
			if(a[j] == '.') path[i][j] = 1; 
		}
	}
	int x, y;
	cin >> x >> y;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i != x && j != y && path[i][j] && (surround(n, m, i, j, path) == 1)) cout << i << " " << j << endl;
		}
	}	
}

int surround(int n, int m, int x, int y, bool path[101][101]){
	int s_path = 0;
	if((x-1>=0) && (path[x-1][y] == 1)) s_path ++;
	if((x+1<n)  && (path[x+1][y] == 1)) s_path ++;
	if((y-1>=0)  && (path[x][y-1] == 1)) s_path ++;
	if((y+1<m) && (path[x][y+1] == 1)) s_path ++;
	
	return s_path;  
}
