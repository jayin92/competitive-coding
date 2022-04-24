#include <bits/stdc++.h>
using namespace std;

const int n = 100;

vector<int> p(n);
vector<int> sz(n, 1);

void init(){
    for(int i=0;i<n;i++){
        p[i] = i;
    }
}

int find(int x){
    if(p[x] == x) return x;
    
    return p[x] = find(x);
}

void merge(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy) return;
    if(sz[fx] < sz[fy]) swap(fx, fy);
    
    p[fy] = fx;
    sz[fx] += sz[fy];
}

int main(){
    
}