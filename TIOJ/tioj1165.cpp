#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;
    while(cin >> a >> b >> c){
        if(a != b+c && b != a+c && c != a+b) cout << "Not Good Pair" << endl;
        else cout << "Good Pair" << endl;
    }
}