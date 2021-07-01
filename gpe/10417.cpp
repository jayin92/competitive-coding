#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

double solve(ll s, ll d){
    double b = (2*s-1);
    double d8 = 8*d;
    double res = (-1 * b + sqrt(b*b+d8)) / 2;

    return res;
}

int main(){
    ll s, d;
    double eps = 1e-10;
    while(cin >> s >> d){
        double n = solve(s, d);
        cerr << n << endl;
        ll ans = s + floor(n - eps);
        cout << ans << endl;
    }
}