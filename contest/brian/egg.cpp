#include "egg.h"

long long height_limit(long long M){
    long long top = M+1;
    long long bot = -1;
    long long mid = (top+bot)/2;
    while(top - bot > 1){
        mid = (top+bot)/2;
        if(is_broken(mid)){
            top = mid;
        } else {
            bot = mid;
        }
    }
    
    return top;
}