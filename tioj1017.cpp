#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int max_[n];
        int min_[n];
        int ans = 0;
        cin >> a[0];
        max_[0] = a[0];
        for(int i=1;i<n;i++){
            cin >> a[i];
            max_[i] = max(max_[i-1], a[i]);
        }
        min_[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--){
            min_[i] = min(min_[i+1], a[i]);
        }
        for(int i=1;i<n-1;i++){
            if(max_[i-1] < a[i] && min_[i+1] > a[i]) ans++;
        }
        cout << ans << endl;
    }    
}