#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        stack<int> s;
        string a;
        cin >> a;
        int ans = 0;
        bool flag = true;
        int c, d;
        c = d = 0;
        for(int i=0;(i<a.size()) && flag;i++){
            if(a[i] == '('){
                c ++;
            } else if(a[i] == ')'){
                d ++;
            }
            if(c < d){
                flag = false;
            }
        }
        if(!flag){
            cout << 0 << endl;
            continue;
        } else {
            if(c != d){
                cout << 0 << endl;
            } else {
                cout << c << endl;
            }
        }
    }
}