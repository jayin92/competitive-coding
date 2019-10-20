#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    cin >> a;
    cin >> b;

    int pointer = 0;

    for(int i=0;i<b.size();i++){
        
        if(a[pointer] == b[i]){
            pointer++;
        } else if(pointer >= 1){
            pointer == 0;
        }
        
    }
    cout << pointer << endl;
}
