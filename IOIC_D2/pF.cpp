#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)

#define ll long long
#define ld long double

using namespace std;

inline ll add(ll a, ll b, ll p){
    ll t = a + b;
    return (t >= p ? t - p : t);
}

inline ll mul(ll a, ll b, ll p) { 
    return (a * b - (ll)((ld)a / p * b) * p);
}


const int N = 1200;

int main(){
    IOS();
    int t;
    int n, m, p;
    ll mod;
    ll a[N][N], b[N][N], c[N][N];
    cin >> t;
    while(t--){
        cin >> n >> m >> p >> mod; 
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> a[i][j], a[i][j] %= mod;
        for(int i=0;i<m;i++)
            for(int j=0;j<p;j++)
                cin >> b[i][j], b[i][j] %= mod;

    
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                c[i][j] = 0;
                for(int k=0;k<m;k++){
                    c[i][j] = add(c[i][j], mul(a[i][k], b[k][j], mod), mod);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<p-1;j++){
                cout << c[i][j] << " ";
            }
            cout << c[i][p-1] << endl;
        }
    }    

    return 0;
}