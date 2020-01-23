#include <bits/stdc++.h>

using namespace std;

struct par{
    int time;
    int score;
    int vir;
};

int main(){
    unsigned long long n;
    cin >> n;
    long long a, b, c;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
    }
    cout << n*(n-1)/2 << endl;
    
}