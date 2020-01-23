/* Matrix Reversing by jayinnn
   Sprout Online Judge Problem 455 */

#include <bits/stdc++.h>

using namespace std;
string ar[105][105];
int arlen[105];
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int len;cin>>len;
        arlen[i]=len;
        for(int j=0;j<len;j++){
            cin>>ar[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int result=1;
        for(int j=0;j<n;j++){
            int temp=1;
            if(j==i){
				continue;
			}
            for(int k=0;k<arlen[i];k++){
                if(ar[i][k]!=ar[j][k]){
                	break;
				} else {
					temp++;
				} 
            }
            if(temp>result) result=temp;
        }
        cout<<result<<endl;
    }
}
