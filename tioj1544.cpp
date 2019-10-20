#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        if(a.size() > b.size()){
            cout << 0 << endl;
        } else if(a.size() < b.size()){
            cout << 1 << endl;
        } else {
            for(int i=0;i<a.size();i++){
                if(a[i] > b[i]){
                    cout << 0 << endl;
                    i = a.size()+1;
                } else if(a[i] < b[i]){
                    cout << 1 << endl;
                    i = a.size()+1;
                }
            }
        }
    }    
}