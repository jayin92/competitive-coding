#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        unsigned long long a, b, n;
        cin >> a >> b >> n;
        if(n % 3 == 0){
            cout << a << endl;
        } else if(n % 3 == 1){
            cout << b << endl;
        } else {
            cout << (a ^ b) << endl;
        }
    }
}