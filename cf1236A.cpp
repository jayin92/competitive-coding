#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        int ans = 0;
        cin >> a >> b >> c;
        if(b == 0){
            cout << 0 << endl;
            continue;
        }
        while(b >= 1 && c >= 2){
            b -= 1;
            c -= 2;
            ans += 3;
        }
        while(b >= 2 && a >= 1){
            b -= 2;
            a -= 1;
            ans += 3;
        }
        cout << ans << endl;
    }    
}