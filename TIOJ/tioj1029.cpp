#include <bits/stdc++.h>

using namespace std;

int sum_(int l, int r, int* sum){
    if(l == 0) return sum[r];
    return sum[r] - sum[l-1];
}

int main(){
    int n;
    cin >> n;
    int a[n];
    int dp[n][n];
    int sum[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        dp[i][i] = a[i];
        if(i == 0){
            sum[0] = a[0];
        } else {
            sum[i] = a[i] + sum[i-1];
        }
    }

    for(int r=1;r<n;r++){
        for(int l=r-1;l>=0;l--){
            dp[l][r] = max(sum_(l+1, r, sum) - dp[l+1][r] + a[l], sum_(l, r-1, sum) - dp[l][r-1] + a[r]);
        }
    }
    cout << dp[0][n-1] << " " << sum_(0, n-1, sum) - dp[0][n-1] << endl;
}