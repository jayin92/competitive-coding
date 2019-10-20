#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        int a, b, c;
        int result = 0;
        cin >> a >> b >> c;
        cout << min(min(a,b), (int)floor((a+b+c)/3)) << endl;
    }
}