#include <bits/stdc++.h>

using namespace std;

int main(){
    while(!cin.eof()){
        string game;
        cin >> game;
        unsigned long long score[2] = {0, 0};
        bool base[4];
        base[1] = 0;
        base[2] = 0;
        base[3] = 0;
        bool bot = false;
        int out = 0;
        for(char i:game){
            if(out == 3){
                out = 0;
                bot = !bot;
                base[1] = 0;
                base[2] = 0;
                base[3] = 0;
            }
            if(i == 'K' || i == 'O'){
                out ++;
                continue;
            }
            if(i == 'W'){
                if(base[1] == 1 && base[2] == 1 && base[3] == 1){
                    score[bot]++;
                } else if(base[1] == 1 && base[2] == 1){
                    base[1] = 1;
                    base[2] = 1;
                    base[3] = 1;
                } else if(base[1] == 1){
                    base[1] = 1;
                    base[2] = 1;
                } else {
                    base[1] = 1;
                }
            }
            if(i == 'S'){
                if(base[1] == 1 && base[2] == 1 && base[3] == 1){
                    score[bot] ++;
                } else if(base[1] && base[2]){
                    base[1] = 1;
                    base[2] = 1;
                    base[3] = 1;
                } else if(base[1] && base[3]){
                    score[bot] ++;
                    base[1] = 1;
                    base[2] = 1;
                    base[3] = 0;
                } else if(base[2] && base[3]){
                    score[bot] ++;
                    base[1] = 1;
                    base[2] = 0;
                    base[3] = 1;
                } else if(base[3]){
                    score[bot] ++;
                    base[1] = 1;
                    base[2] = 0;
                    base[3] = 0;
                } else if(base[2]){
                    base[1] = 1;
                    base[2] = 0;
                    base[3] = 1;
                } else if(base[1]){
                    base[1] = 1;
                    base[2] = 1;
                    base[3] = 0;
                } else {
                    base[1] = 1;
                }
            }
            if(i == 'D'){
                if(base[1] == 1 && base[2] == 1 && base[3] == 1){
                    score[bot] += 2;
                    base[1] = 0;
                    base[2] = 1;
                    base[3] = 1;
                } else if(base[1] && base[2]){
                    score[bot] += 1;
                    base[1] = 0;
                    base[2] = 1;
                    base[3] = 1;
                } else if(base[2] == 1 && base[3] == 1){
                    score[bot] += 2;
                    base[1] = 0;
                    base[2] = 1;
                    base[3] = 0;
                } else if(base[1] == 1 && base[3] == 1){
                    score[bot] ++;
                    base[1] = 0;
                    base[2] = 1;
                    base[3] = 1;
                } else if(base[1] == 1){
                    base[1] = 0;
                    base[2] = 1;
                    base[3] = 1;
                } else if(base[2] == 1 || base[3] == 1){
                    score[bot] ++;
                    base[1] = 0;
                    base[2] = 1;
                    base[3] = 0;
                } else {
                    base[2] = 1;
                }
            }
            if(i == 'T'){
                if(base[1] && base[2] && base[3]){
                    score[bot] += 3;
                    base[1] = 0;
                    base[2] = 0;
                    base[3] = 1;
                } else if((base[1] && base[2]) || (base[2] && base[3]) || (base[1] && base[3])){
                    score[bot] += 2;
                    base[1] = 0;
                    base[2] = 0;
                    base[3] = 1;
                } else if(base[1] || base[2] || base[3]){
                    score[bot] += 1;
                    base[1] = 0;
                    base[2] = 0;
                    base[3] = 1;
                } else {
                    base[3] = 1;
                }
            } 
            if(i == 'H'){
                score[bot] ++;
                for(int i=1;i<=3;i++){
                    if(base[i]) score[bot] ++;
                }
                base[1] = 0;
                base[2] = 0;
                base[3] = 0;
            }            
        }
        if(!cin.eof()){
            cout << score[0] << " " << score[1] << endl;
        }
    }
}