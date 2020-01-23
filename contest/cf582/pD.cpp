#include <bits/stdc++.h>
#include <iostream>

using namespace std;




int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);

    int result = 1 << 31 - 1;
    for(int i=0;i<=n-m;i++){
        int re  = 0;
        for(int j=i+1;j<i+m;j++){
            int tmp = a[j];
            while(tmp != a[i]){
                tmp = tmp >> 1;
                result ++;
            }
        }
    }
}