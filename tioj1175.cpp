#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    vector<int> dp(n, 1);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    dp[0] = 1;
    int ans = dp[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}