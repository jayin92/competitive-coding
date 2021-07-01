#include "pokemon.h"

inline double prob(int n){
    return (double)1.0 / (double)pow(3, n);
}

pair<int,int> battle(bool A_alive, int A_protect, bool B_alive, int B_protect, bool C_alive, int C_protect, bool D_alive, int D_protect){
    double hold = 0.5;
    double hold2 = 0.2;
    int res_a, res_d;
    if(A_alive){
        if(prob(A_protect) <= hold){
            if(prob(B_protect) < prob(C_protect)){
                res_a = 1;
            } else {
                res_a = 2;
            }
        } else if(prob(B_protect) <= hold2 && B_alive){
            res_a = 1;
        } else if(prob(C_protect) <= hold2 && C_alive){
            res_a = 2;
        } else {
            res_a = 0;
        }
    } else {
        res_a = 0;
    }

    if(B_alive){
        if(prob(D_protect) <= hold){
            if(prob(B_protect) < prob(C_protect)){
                res_d = 1;
            } else {
                res_d = 2;
            }
        } else if(prob(B_protect) <= hold2 && B_alive){
            res_d = 1;
        } else if(prob(C_protect) <= hold2 && C_alive){
            res_d = 2;
        } else {
            res_d = 0;
        }
    } else {
        res_d = 0;
    }
    return make_pair(res_a, res_d);
}
