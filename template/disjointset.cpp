#include <bits/stdc++.h>

using namespace std;

struct DS{
    int p[n];
    void init(int n){
        for(int i=0;i<n;i++){
            p[i] = i;
        }
    }
    void Find(int x){
        return x == p[x] ? x : p[x] = Find(x);
    }
    void Union(int x, int y){
        p[Find(x)] = Find(y);
    }
};