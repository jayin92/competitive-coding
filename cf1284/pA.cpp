#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x % y);
}

int main(){
    int n, m;
    cin >> n >> m;
    int g = n * m / gcd(n, m);
    string a[n];
    string b[m];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    long long t;
    cin >> t;
    vector<string> c;
    int t1, t2;
    t1 = t2 = 0;
    for(int i=0;i<g;i++){
        t1 %= n;t2 %=m;
        c.push_back(a[t1] + b[t2]);
        t1 ++;t2++;
    }
    int y;
    while (t--){
        cin >> y;
        cout << c[(y - 1) % g] << endl;
    }
    

}