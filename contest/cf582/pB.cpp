#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int m;
    cin >> m;
    while(m--){
        cin >> n;
        int a[n];
        int mini[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        mini[n-1] = a[n-1];
        for(int i = n-2;i>=0;i--){
            mini[i] = min(mini[i+1], a[i]);
        }
        int result = 0;
        for(int i=0;i<n;i++){
            if(a[i] > mini[i]) result ++;
        }

        cout << result << endl;
    }
}