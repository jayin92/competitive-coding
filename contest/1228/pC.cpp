#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

vector<unsigned long long> prime(int x){
    vector<unsigned long long> res;
    for(int i=2;i<=sqrt(x)+1;i++){
        if(x % i == 0){
            x /= i;
            res.push_back(i);
        }
    }

    return res;
}

unsigned long long g(int x, int p){
    unsigned long long res = p;
    
    while(x % res == 0){
        res *= p;
    }
    printf("g(%d, %d)=%d\n", x, p, res/p);
    return res / p;
}

unsigned long long f(int x, int y, vector<unsigned long long> pr){
    
    unsigned long long res = 1;
    for(int i:pr){
        res =  ((res % MOD) * (g(y, i) % MOD)) % MOD;
    }

    return res;
}

int main(){
    unsigned long long x, n;
    cin >> x >> n;
    unsigned long long res = 1;
    vector<unsigned long long> pr = prime(x);
    for(int i:pr){
        cout << i << endl;
    }
    for(unsigned long long i=1;i<=n;i++){
        cout << f(x, i, pr) << " ";
        cout << res << endl;
        res = (res * f(x, i, pr)) % MOD;
    }
    cout << endl;
    cout << res << endl;
}