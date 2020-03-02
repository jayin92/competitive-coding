// AC

#include "lib1044.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = Initialize();
    int higher = n+1;
    int lower = 0;

    while(higher-lower>1){
        if(Guess(int((higher+lower)/2))) higher = int((higher+lower)/2);
        else lower = floor((higher+lower)/2);
    }

    Report(higher);

}