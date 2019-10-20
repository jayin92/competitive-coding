#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int main(){
    int a, b;
    while(cin >> a >> b){
        if(!a && !b) return 0;
        cout << gcd(a, b) << endl;
    }
}