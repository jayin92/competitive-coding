#include "lib1168.h"
#include <bits/stdc++.h>

using namespace std;

set <long long> a;

void pop_big(){
    auto it = prev(a.end());
    a.erase(it);
}

void pop_small(){
    auto it = a.begin();
    a.erase(it);
}

int big(){
    return *prev(a.end());
}

int small(){
    return *a.begin();
}

void push(int x){
    a.insert(x);
}


