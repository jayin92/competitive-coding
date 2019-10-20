#include <bits/stdc++.h>

using namespace std;

unsigned long long cal(unsigned long long n){
    if(n == 1 || n == 0) return 1;
    else return (cal(n/2) * 2);
}


int main(){
    int n;
    while(cin >> n){
        if(n == 0) return 0;
        unsigned long long m;
        unsigned long long ans = 0;
        ans += cal(n);
        while(cin >> m){
            if(m == 0) break;
            ans += cal(m);
        }
        cout << ans << endl;
    }
}