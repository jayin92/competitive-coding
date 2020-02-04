#include <bits/stdc++.h>

using namespace std;

int main(){
	int map[505][505];
	bool ma[505][505];
	int n, m, q, x, y;	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> map[i][j];
			ma[i][j] = 1;
		}
	}
	cin >> q;
	int ans;
	while(q--){
		cin >> x >> y;
		ans = 0;
		if(ma[x][y]){
			ma[x][y] = 0;
			ans += map[x][y];
		}
		for(int i=y+1;i<=m;i++){
			if(ma[x][i]){
				ma[x][i] = 0;
				ans += map[x][i];
			} else {
				break;
			}
		}
		for(int i=y-1;i>=0;i--){
			if(ma[x][i]){
				ma[x][i] = 0;
				ans += map[x][i];
			} else {
				break;
			}
		}
		for(int i=x+1;i<=n;i++){
			if(ma[i][y]){
				ma[i][y] = 0;
				ans += map[i][y];
			} else {
				break;
			}
		}
		for(int i=x-1;i>=0;i--){
			if(ma[i][y]){
				ma[i][y] = 0;
				ans += map[i][y];
			} else {
				break;
			}
		}
		cout << ans << endl;
	}
}
