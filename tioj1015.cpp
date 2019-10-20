#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long m, n;
    while(cin >> m >> n && (m||n)){
        unsigned long long y = max(m, n);
        unsigned long long x = min(m, n);

        cout << x*(x+1)*(y-x) / 2 + x*(x+1)*(2*x+1) / 6 << endl;

    }
}