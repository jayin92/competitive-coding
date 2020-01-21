#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 3;
    for(int i=2;i<=n;i++){
        int len = i*(i-1) / 2;
        cout << "len:" << len << endl;
        int a = 1 << (len);
        for(int j=a-1;j>=0;j--){
            int tmp = 1;
            cout << "j:" << j << endl;
            vector<bool> c;
            while(tmp <= j){
                cout << j << " " << tmp << endl;
                c.push_back(j & tmp);
                tmp = tmp << 1;
            }
            for(int i:c){
                cout << i << " ";
            }
            cout << endl;
        }
         
    }
}