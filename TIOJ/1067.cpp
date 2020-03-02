#include <bits/stdc++.h>

using namespace std;

int gcd(int m, int n) { 
    int r = 0; 

    while(n != 0) { 
        r = m % n; 
        m = n; 
        n = r; 
    } 

    return m; 
}

int main(){
    while(true){
        int n, m;
        int ans = -1;
        cin >> n >> m;
        if(!n && !m) break;
        bitset<1005> b;
        char a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        while(b.count() != n){
            string temp = "";
            int cot = 0;
            for(int i=n-1;i>=0;i--){
                if(b[i]){
                    cout << a[i] << endl;
                    temp += a[i];
                    cot ++;
                }
            }
            if(cot > 0){
                if(gcd(stoi(temp), m) == 0){
                    ans = max(ans, cot);
                }
            }
        }
        cout << ans << endl;
    }
}