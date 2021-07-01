#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int n = opt<int>(1);
    int MAX = opt<int>(2);


    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i] = rnd.next(1, MAX);
    }
    printf("1\n%d\n", n);
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }

    printf("\n");

    
}