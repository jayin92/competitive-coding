#include <bits/stdc++.h>

using namespace std;




int main(){
    int n, q;
    cin >> n >> q;
    int ans[n+1];
    for(int i=1;i<=n;i++){
        ans[i] = -1;
    }
    int l, r, c;
    vector<vector<int>> tmp(n+1);
    while(q--){
        cin >> l >> r >> c;
        if(c == 0){
            for(int i=l;i<=r;i++){
                ans[i] = 0;
            }
        } else if(c == 1){
            for(int i=l;i<=r;i++){
                tmp[i].push_back(q);
            }
        }
    }
    // for(auto j:tmp){
    //     for(auto i:j){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    while(true){
        int max_i = 0; 
        for(int i=1;i<=n;i++){
            if(tmp[i].size() > tmp[max_i].size()) max_i = i;
        }
        if(max_i == 0) break;
        ans[max_i] = 1;
        for(auto i:tmp[max_i]){
            for(int j=1;j<=n;j++){
                auto it = find(tmp[j].begin(), tmp[j].end(), i);
                if(it != tmp[j].end()) tmp[j].erase(it);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(ans[i] == -1) ans[i] = 0;
        cout << ans[i];
        if(i != n) cout << " ";
    }
    cout << endl;
}