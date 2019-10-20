#include <bits/stdc++.h>

using namespace std;

int main(){
    string tree;
    int n, ary;
    int depth[];
    bool rabbit;
    while(cin>>tree && !cin.eof()){
        rabbit = 1;
        for(int i=0;i<tree.size();i++){
            if(tree[i] == "*"){
                n++;
            }
            if(tree[i] == "(" && rabbit){
                
                depth[i] =;
            }
            if(tree[i] == ")" && rabbit){
                rabbit = 0;
            }
        }
    }
    cout>>n>>depth>>ary;
}