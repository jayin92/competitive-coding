#include <bits/stdc++.h>
#define ll unsigned long long


using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q, a, b, p, t;
	cin >> n >> m >> q;
	bool com[n][m];
	string tmp1;
	int res = -1;
	for(int i=0;i<n;i++){
		cin >> tmp1;
		for(int j=0;j<m;j++){
			com[i][j] = tmp1[j] - '0';
		}
	}
	
	for(int i=0;i<m;i++){
		vector<int> tmp;
		bool z[m] = {0};
		int d = 0;		
		for(int j=0;j<n;j++){
			if(com[j][i] == 0){
				for(int k=0;k<m;k++){
					if(z[k] == 1) continue;
					if(com[j][k]){
						z[k] = 1;
						d++;
					}
				}
			} else {
				continue;
			}
		}
		res = max(res, d);
	}
	cout << res << endl;
	while(q--){
		res = -1;
		cin >> p >> t;
		com[p-1][t-1] = !com[p-1][t-1];	
		for(int i=0;i<m;i++){
		vector<int> tmp;
		bool z[m] = {0};
		int d = 0;		
		for(int j=0;j<n;j++){
			if(com[j][i] == 0){
				for(int k=0;k<m;k++){
					if(z[k] == 1) continue;
					if(com[j][k]){
						z[k] = 1;
						d++;
					}
				}
			} else {
				continue;
			}
		}
		res = max(res, d);
	}
	cout << res << endl;

}
}

