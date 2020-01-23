#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(){
    ll a, b, k;
    cin >> a >> b >> k;
    long long tmp = a - k;
    cout << ((a >= k) ? a - k : 0) << " " << ((a >= k) ? b : ((a+b > k) ? a+b-k : 0)) << endl;

}