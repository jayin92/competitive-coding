#include <bits/stdc++.h>

typedef unsigned long long ll;

using namespace std;

ll solve(){
    ll g;
    cin >> g;
    g *= 2;
    ll ans = 0;
    for(ll i=1;i*i<=g;i++){
        if(g % i == 0){
            ll a = i;
            ll b = g / i;
            
            ll n1 = (b-a-1)/2;
            ll n2 = (a+b-1)/2;

            if((1+n2)*n2/2 - (1+n1)*n1/2 == g/2) ans ++;
        }
    }
}

int main(){
    int t;
    cin >> t;
    int c = 1;
    while(t--){
        ll ans = solve();
        cout << "Case #" << c++ << ": " << ans << endl;
    }
    
}