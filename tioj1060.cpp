#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int hdp[MAX], fdp[MAX];
bool hc[MAX], fc[MAX];

int g(int x){
    if(x <= 2) return x*x -1;
    return 2;
}

int h(int x){
    if(hc[x]){
        return hdp[x];
    }
    hc[x] = 1;
    if(x < 2) return hdp[x] = -1;
    return hdp[x] = 2 + h(x-1) - h(x-2);
}
int f(int x){
    if(fc[x]){
        return fdp[x];
    }
    fc[x] = 1;
    if(x > h(x)){
        return fdp[x] = f(x-1) - h(x);
    }
    else if(x < h(x)) return fdp[x] = f(g(x)) - g(x);
    return fdp[x] = 1;
}


int main(){
    int x;
    cin >> x;
    cout << f(x) << endl;
}