#incldue <iostream>
#incldue <algorithm>
#include <vector>
using namespace std;
int main(){
	int n, k;
	
	cin >> n >> k;
	int tree[n], p[n];
	int sum = 0;
	vector<int> temp;
	
	for(int i=0;i<n;i++){
		cin >> tree[i];
	}
	for(int i=0;i<n;i++){
		cin >> p[i];
	}
	for(int i=0;i<n;i++){
		sum += tree[i];
	} 
	if(sum<k){
		cout << "-1";
		return 0;
	}
	
	else{
		for(int i=0;i<n;i++){
			if(tree[i]==k){
				cout << "0" << endl;
				return 0;
			}
		}
		int max = tree[0];
		int index = 0;
		for(int i=0;i<n;i++){
			if(max < tree[i]){
				max = tree[i];
				index = i;
			}
		}
		if(max<k){
			int diff = k-max;
			for(int i=0;i<n;i++){
				if(tree[i]<=diff){
					temp.push_back(i);
				}
			}
			int min = tree[0];
			int min_index = 0;
			for(int i=0;i<temp.size();i++){
				if(min>tree[temp[i]])
			}
		}
		if(max>k){
			
		}
	}
}
