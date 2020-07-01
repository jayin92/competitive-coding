#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int m = n*2;
    ll a[m][m];
    ll res = -1;
    ll total = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            total += a[i][j];
        }
    }
    vector<bool> c;
    for(int i=0;i<n-1;i++){
        c.push_back(0);
    }
    for(int j=0;j<n;j++){' 
        c.push_back(1);
    }
    do{
        ll tmp = 0;
        c.push_back(0);
        for(int j=0;j<m;j++){
            for(int k=j+1;k<m;k++){
                if(c[k] == c[j]) tmp += a[k][j];  
            }
        }
        c.pop_back();
        res = min(tmp, res);
    } while(next_permutation(c.begin(), c.end()));
    cout << total / 2 - res << endl;    
}



