#include <bits/stdc++.h>
#include <string>
#include <cmath>

using namespace std;

int gcd(int i,int j){
    int a;
    if(j>i){
        a=i;
        i=j;
        j=a;
    }
    a=i/j;
    i=i-a*j;
    if(i==0){
        return j;
    }
    else if(j==0){
        return i;
    }
    else{
        return gcd(j,i);
    }
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b);
}

