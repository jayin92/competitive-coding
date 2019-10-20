#include <bits/stdc++.h>

using namespace std;

int face(int a){
    if(a==1 || a==2){
        return 1;
    }
    else{
        return face(a-1) + face(a-2);
    }
}

int main(){
    int a;
    cin >> a;
    cout << face(a);
}