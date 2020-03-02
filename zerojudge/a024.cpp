#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll gcd(ll m, ll n){
    if(n == 0) return m;
    else return gcd(n, m%n);
}

int main(){
    ll a, b;
    while(cin >> a >> b) cout << gcd(a, b) << endl;;
}