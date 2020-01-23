#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(){
    int t;
    cin >> t;
    int n, m, q;
    for(int k=1;k<=t;k++){
        cin >> n >> m >> q;
        vector<bool> p(n+5, 1);
        ll res = 0;
        int tmp;ti
        int r;
        vector<int> f(n+5, 0);
        for(int i=0;i<m;i++){
            cin >> tmp;
            p[tmp] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                 if(p[j]) f[i]++;
            }
            // cout << f[i] << endl;
        }
        for(int i=0;i<q;i++){
            cin >> r;
            res += f[r];
        }
        cout <<"Case #" << k << ": " << res << endl;
    }
}