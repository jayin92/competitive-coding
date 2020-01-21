#include <bits/stdc++.h>

#define ll long long
#define ld long double
inline ll magic(ll a, ll b, ll m) { // a * b % m
    return (a * b - (ll)((ld)a * b / m) * m);
}

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, p;
        ll mod;
        cin >> n >> m >> p >> mod;
        ll a[n][m], b[m][p], c[n][p];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> a[i][j];
        for(int i=0;i<m;i++)
            for(int j=0;j<p;j++)
                cin >> b[i][j];

        for(int i=0;i<n;i++)
            for(int j=0;j<p;j++)
                c[i][j] = 0;

    
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                for(int k=0;k<m;k++){
                    c[i][j] += magic(a[i][k], b[k][j], mod);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                cout << c[i][j] << (j == p-1 ? "" : " ");
            }
            cout << endl;
        }
    } 

    

    return 0;
}