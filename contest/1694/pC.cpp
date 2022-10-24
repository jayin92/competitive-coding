#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    int cnt = a[0];
    if(a[0] < 0 || a[n-1] > 0){
        cout << "NO" << endl;
        return;
    }
    for(int i=1;i<n-1;i++){
        cnt = a[i] + cnt;
        if(cnt < 0){
            cout << "NO" << endl;
            return;
        }
        if(cnt == 0){
            for(int j=i+1;j<n;j++){
                if(a[j] != 0){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    if(cnt != -a[n-1]){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}