#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, m, x, y, maxi;
        cin >> n >> m;
        ll tmp;
        x = y = 0;
        maxi = -1e9-5;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> tmp;
                if(tmp > maxi){
                    maxi = tmp;
                    x = i;
                    y = j;
                }
            }
        }
        ll ans = max(x+1, n-x) * max(y+1, m-y);
        cout << ans << endl;
    }
}