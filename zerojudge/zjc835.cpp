#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define N 1000005
#define W 1 << 20 + 1

int main(){
    ll n, m;
    cin >> n >> m;
    ll W = 1 << m;
    ll w[W];
    ll v[n+1];
    ll dp[W+10] = {0};
    
    for(ll i=0;i<n;i++){
        cin >> w[i] >> v[i];
        w[i] = 1 << w[i];
    }
    
    for(ll i=0;i<n;i++){
        for(ll j=W;j - w[i] >=0;j--){
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }

    cout << dp[W] << endl;

}