#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0) break;
        
        int sum = 0;
        int a;
        int ma = -1, mi = 100005;
        for(int i=0;i<n;i++){
            cin >> a;
            ma = max(ma, a);
            mi = min(mi, a);
            sum += a;
        }
        cout << fixed << setprecision(2) << (double)(sum-mi-ma) / (n-2) << endl;
    }    
}