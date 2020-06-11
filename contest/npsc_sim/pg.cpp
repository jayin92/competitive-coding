#include <bits/stdc++.h>

using namespace std;



int main(){
	int t;
	string player[5] = {"Saki", "Megumin", "Rem", "Sagiri", "Kirino"};
	int n = 5;
	int a[5][5];
	cin >> t;
	bool temp = 1;
	while(t--){
		vector<string> res;
		vector<int> win(5, 0);
		
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				cin >> temp;
				if(j > i){
					if(temp) win[i] ++;
					else win[j]++;
				}
			}	
		}
		int max_ = win[0];
		for(int i=1;i<n;i++){
			max_ = max(max_, win[i]);
		}
		for(int i=0;i<n;i++){
			if(win[i] == max_){
				res.push_back(player[i]);
			}
		}
		cout << res.size() << endl;
		for(auto i:res){
			cout << i << endl;
		}
	}

}

