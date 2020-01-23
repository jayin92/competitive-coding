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
    i=a*j;
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
    int a,b,c,d,i,j;
    char word[10];
    cin >> word;
    a=(int)word[0]-48;
    b=(int)word[2]-48;
    c=(int)word[3]-48;
    d=(int)word[5]-48;
    b=b*d;
    a=a*d+c*b;
    c=gcd(a,b);
    a/=c;
    b/=c;
    cout << a << '/' << b;

}