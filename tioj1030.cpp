#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(true){
        cin >> n;
        if(n == 0) return 0;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        unsigned long long ans = 2;
        sort(a, a+n);
        // cout << a[0] << endl;
        for(int i=0;i<n;i++){
            ans += a[i];
        }
        ans += a[n-1] - 1;
        cout << ans << endl;
    }
}