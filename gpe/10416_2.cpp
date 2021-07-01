#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        long long ans = 0;
        for(int i=1;i<=n;i++){
            ans += (long long)pow(i % 10, i);
            ans %= 10;
            while(ans <= 0) ans += 10;
            ans %= 10;
        }
        cout << ans % 10 << endl;
    }
}