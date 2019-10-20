#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int case_ = 0;
    while(cin >> n){
        case_ ++;
        if(n == 0) break;
        int a[n];
        int ans = 0;
        for(int i=0;i<n;i++){
            scanf("%I64u", &a[i]);
        }
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(a[i] < a[j]){
                    swap(a[i], a[j]);
                    ans ++;
                }
            }
        }
        cout << "Case #" << case_ <<": " << ans << endl;
    }
}