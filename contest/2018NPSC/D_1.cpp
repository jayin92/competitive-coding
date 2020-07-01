#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	unsigned long long n, k;
	unsigned long long result = 20000000001;
	cin >> n >> k;
	unsigned long long tree[n];
	unsigned long long p[n];
	
	for(int i=0;i<n;i++){
		cin >> tree[i];
	}
	for(int i=0;i<n;i++){
		cin >> p[i];
	}

	for(unsigned long long i=0;i<n;i++){
		if(tree[i] == k){
			cout << "0" << endl;
			return 0;
		}
		else if(tree[i]>k){
			if(p[i]<result){
				result = p[i];
			}
		}
	}
	for(unsigned long long i=0;i<n;i++){
		for(unsigned long long j=i+1;j<n;j++){
			if(tree[i]+tree[j]==k){
				cout << "0" << endl;
				return 0;
			}
			else if(tree[i]+tree[j]>k){
				if(tree[i]>k | tree[j]>k){
					if(tree[i]>k){
						if(result > p[i]){
							result = p[i];
						}
					}
					else if(tree[j]>k){
						if(result > p[j]){
							result = p[j];
						}
					}
				}
				if(result > min(p[i],p[j])) {
					result = min(p[i],p[j]);
				}
			}b			
		}
	}

	if(result == 20000000001){
		cout << "-1" << endl;
	}
	else{
		cout << result << endl;
	}
	return 0;
}
	
