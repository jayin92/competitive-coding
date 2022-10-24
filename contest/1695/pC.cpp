#include <bits/stdc++.h>

using namespace std;

bool update(vector<int> &cnt, int m){
    int sz = cnt.size();
    cnt[sz-1] ++;
    for(int i=sz-1;i>1;i--){
        if(cnt[i] > m){
            cnt[i] = 1;
            cnt[i-1] ++;
        } else {
            return true;
        }
    }
    if(cnt[1] > 1) return false;
    else return true;
}

void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<vector<int>> a(n, vector<int>(m, 0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i+1][j+1] = dp[i+1][j] + a[i][j];
        }
    }
    vector<int> cnt(n+1, 1);
    while(true){
        // for(int i=1;i<=n;i++){
        //     cout << cnt[i] << " ";
        // }
        int ans = 0;
        bool flag = false;
        for(int i=1;i<n;i++){
            ans += dp[i][cnt[i+1]] - dp[i][cnt[i] - 1];
            if(cnt[i] > cnt[i+1]){
                // cout << "error";
                flag = true;
                break;
            }
        }
        // cout << endl;
        ans += dp[n][m] - dp[n][cnt[n] - 1];
        if(!flag && ans == 0){
            cout << "YES" << endl;
            return;
        }
        if(!update(cnt, m)) break;
    }
    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}