/* Chocobo Racing by jayinnn
   Sprout Online Judge Problem 99
   
   Using linked-list liked array to solve this problem*/
   
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int m;
    cin >> n;
    cin >> m;
    int a, b;
    int next[n+1];
    int prev[n+1];
    int temp1;
    int temp2;
    for(int i=1;i<=n;i++){
        next[i] = i+1;
        prev[i] = i-1;
    }
    prev[0] = 0;
    next[0] = 1;
    next[n] = 0;
    for(int i=0;i<m;i++){
        cin >> a >> b;	
        if(a && prev[b] != 0){
            temp1 = prev[prev[b]];
            temp2 = next[temp1];
			next[prev[b]] = next[b];
            next[prev[prev[b]]] = b;
            prev[prev[b]] = b;
            prev[next[b]] = prev[b];
            prev[b] = temp1;
            next[b] = temp2;            
        } else if(!a) {
            next[prev[b]] = next[b];
            prev[next[b]] = prev[b];
            prev[b] = b;
            next[b] = b;            
        }       
		
    }
    for(int i=1;i<=n;i++){
    	if(prev[i] == 0){
    		while(next[i] != 0){
    			cout << i << " ";
    			if(next[i] == 0){
    				break;
				}
				i = next[i];
			}
			cout << i << endl;
			break;
		}
	}
}
