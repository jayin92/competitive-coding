#include <bits/stdc++.h>

using namespace std;

int main(){
    string tree;
    while(cin>>tree &&!cin.eof()){
    	int n, m,k;
    	n=m=k=0;
    	int depth[tree.size()]=0;
    	int ary[tree.size()]=0;
   		bool rabbit, bear, koala;
        rabbit=bear=koala=1;
        for(int i=0;i<tree.size();i++){
            if(tree[i] == '*'){
                n++;
            }
            if(tree[i] == '(' ){
                depth[i]=depth[i-1]+1;
                k=k+1;
            }
            if(tree[i] == ')' ){
                depth[i]=depth[i-1]-1;
            }
        }
        for(int l=0;l<k;l++){
        	for(int i=0;i<tree.size();i++){
        		int b=0;
    	        if(tree[i] == '*' && bear && koala){
       		        ary[l]=ary[l]+1;
        	    }
            	if(tree[i] == '(' && rabbit){
                	b=b+1;
                	if(b==l){
                		koala=1;
						rabbit=0;
					}
            	}
            	if(tree[i] == '(' &&! rabbit){
                	bear=0;
            	}
            	if(tree[i] == ')' && koala){
            	    ary[l]=ary[l]+1;
                	bear=1;
            	}
        	}
		}
		for(int j=0; j<tree.size();j++){
    		if(depth[m]<depth[j]){
    			m=j;
			}
		}
		for(int j=0; j<tree.size();j++){
    		if(ary[k]<ary[j]){
    			k=j;
			}
		}
		cout<<n<<" "<<depth[m]+1<<" "<<ary[k];
    }
}
