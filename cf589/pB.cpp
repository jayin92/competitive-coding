#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    int r[h];
    int c[w];
    int grid[h][w];

    for(int i=0;i<h;i++){
        cin >> r[i];
    }
    for(int i=0;i<w;i++){
        cin >> c[i];
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            grid[i][j] = -1;
        }
    }
    for(int i=0;i<h;i++){
        if(r[i] == 0){
            grid[i][0] = 0;
        } else {
            for(int j=0;j<r[i];j++){
                grid[i][j] = 1;
            }
            if(r[i] < w){
                grid[i][r[i]] = 0;
            }
        }
        
    }
    for(int i=0;i<w;i++){
        if(c[i] == 0){
            if(grid[0][i] == 1){
                cout << 0 << endl;
                return 0;
            }
            grid[0][i] = 0;
        }
        else{
            for(int j=0;j<c[i];j++){
                if(grid[j][i] == 0){
                    cout << 0 << endl;
                    return 0;
                }
                grid[j][i] = 1;
            }
            if(c[i] < h){
                if(grid[c[i]][i] == 1){
                    cout << 0 << endl;
                    return 0;
                }
                grid[c[i]][i] = 0;
            }
        }
    }
    unsigned long long total = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j] == -1){
                total++;
            }
        }
    }
    unsigned long long result = 1;
    for(int i=1;i<=total;i++){
        result = ((result % MOD) * 2) % MOD;
    }
    cout << result << endl;
}