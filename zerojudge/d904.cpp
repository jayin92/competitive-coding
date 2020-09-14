#include <bits/stdc++.h>

using namespace std;

const int iNF = 0x3f3f3f3f;

/********** Good Luck :) **********/
int main () {
    int n, t;
    cin >> n >> t;
    vector<int> dp(n+1, iNF);
    dp[0] = 0;
    while(t--){
        int c;
        cin >> c;
        for(int i=c;i<=n;i++){
            dp[i] = min(dp[i - c] + 1, dp[i]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}