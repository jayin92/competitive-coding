#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int x = min(a, b);
        for(int i=0;i<x;i++){
            cout << "10";
        }
        a -= x;
        b -= x;
        while(a != 0){
            cout << 0;
            a --;
        }
        while(b != 0){
            cout << 1;
            b --;
        }
        cout << endl;
    }
}