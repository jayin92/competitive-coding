#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


/********** Good Luck :) **********/
int main () {

    int d[10][4] = {
        {0},
        {1},
        {2, 4, 8, 6},
        {3, 9, 7, 1},
        {4, 6},
        {5},
        {6},
        {7, 9, 3, 1},
        {8, 4, 2, 6},
        {9, 1},
    };
    
    int d_sz[10] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 1};
    int a[100];
    a[0] = 0;
    for(int n=1;n<100;n++){
        int ans = 0;
        for(ll i=1;i<=n;i++){
            ans += d[i%10][(i-1)%(d_sz[i%10])];
            if(ans <= 0) ans += 10;
            ans %= 10;
        }
        a[n] = ans % 10;
    }
    string s;
    
    while(cin >> s){
        if(s == "0") break;
        int sz = s.size();
        string tmp = "";
        int x = (sz >= 2 ? (s[sz-2] - '0') : 0) * 10 + (s[sz-1] - '0');
        cout << a[x] << endl;
    }

    return 0;
}