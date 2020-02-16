#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
    int a,b,i,j=1;
    double e=1;
    cin >> a;
    for(i=1;i<a;i++){
        j=j*i;
        e+=(1/j);
    }
    cout << e;
}