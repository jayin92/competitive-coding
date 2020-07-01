#include <bits/stdc++.h>

#define ll unsigned long long
using namespace std;
vector<int> people;
vector<int> combination;
int m;
ll res = -1;
ll total = 0;vg
ll a[30][30];
void go(int offset, int k , int m, ll a[30][30]){
	bool c[m]={0};
	if (k == 0) {
//		for(int i=0; i< combination.size(); i++){
//    	cout<<combination[i]<<" ";
//		}
//	cout<<endl;
    ll tmp = 0;
    for(int i=0; i< combination.size(); i++){
    	c[combination[i]]=1;
	}
	for(int j=0;j<m;j++){
		for(int k=j+1;k<m;k++){
			if(c[k] == c[j]) tmp += a[k][j];  
		}
	}
	res = min(tmp, res);
    return;
  }
  for (int i = offset; i <= people.size() - k; ++i) {
    combination.push_back(people[i]);
    go(i+1, k-1,m,a);
    combination.pop_back();
  }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	m = n*2;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
			total += a[i][j];
		}
	}
	for(int i=0;i<m;i++){
		people.push_back(i);
	}

	go( 0 , n, m, a);
		
	cout << total / 2 - res << endl;
	
	return 0;
}

