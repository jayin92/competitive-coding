#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int n = opt<int>(1);
    int MAX = opt<int>(2);
    int l = rnd.next(1, MAX);
    int r = rnd.next(l+1, MAX);

    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i] = rnd.next(1, MAX);
    }
    shuffle(a.begin(), a.end());
    printf("1\n");
    printf("%d %d %d\n", n, l, r);
    for(auto i:a){
        printf("%d ", i);
    }
    printf("\n");
    
}