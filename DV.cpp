#include <bits/stdc++.h>
#define INF 10000
using namespace std;
 
int main(){
    int n = 9;
    vector<vector<vector<int> > > cost(n, vector<vector<int> >(n, vector<int>(n, INF)));
    vector<vector<bool> > adj(n, vector<bool>(n, false));
   
    cost[0][0][1] = 1; cost[0][0][3] = 2; cost[0][0][4] = 5; // A
    cost[1][1][0] = 1; cost[1][1][4] = 3; cost[1][1][2] = 5; // B
    cost[2][2][1] = 5; cost[2][2][4] = 1; cost[2][2][5] = 2; // C
    cost[3][3][0] = 2; cost[3][3][4] = 5; cost[3][3][6] = 4; // D
    cost[4][4][0] = 5; cost[4][4][1] = 3; cost[4][4][2] = 1; cost[4][4][3] = 5; cost[4][4][5] = 2; cost[4][4][6] = 2; cost[4][4][7] = 1; cost[4][4][8] = 2;// E
    cost[5][5][2] = 2; cost[5][5][4] = 2; cost[5][5][8] = 1; // F
    cost[6][6][3] = 4; cost[6][6][4] = 2; cost[6][6][7] = 3; // G
    cost[7][7][6] = 3; cost[7][7][4] = 1; cost[7][7][8] = 2;
    cost[8][8][7] = 2; cost[8][8][4] = 2; cost[8][8][5] = 1;
    
    auto ori_cost(cost);
    auto tmp(cost);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(cost[i][j][k] != INF){
                    adj[j][k] = adj[k][j] = true;
                }
            }
            adj[j][j] = true;
            cost[i][i][i] = 0;
        }
    }
    printf("Step 0\n");
    for(int i=0;i<n;i++){
        printf("Node %c:\n", ('A'+i));
        printf("     ");
        for(int j=0;j<n;j++){
            printf("%4c", ('A'+j));
        }
        printf("\n");
        for(int j=0;j<n;j++){
            if(adj[i][j]){
                printf("%4c ", ('A'+j));
                for(int k=0;k<n;k++){
                    if(cost[i][j][k] == INF){
                        printf("%4s", "INF");
                    } else {
                        printf("%4d", cost[i][j][k]);
                    }
                }
                printf("\n");
            }
        }
    }
    int step = 1;
    bool stable = false;
    while(!stable){
        bool changed = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]){
                    for(int k=0;k<n;k++){
                        if(tmp[i][j][k] > cost[j][j][k]){
                            tmp[i][j][k] = cost[j][j][k];
                            changed = true;
                        }
                    }
                    for(int k=0;k<n;k++){
                        if(tmp[i][i][k] > ori_cost[i][i][j] + cost[j][j][k]){
                            tmp[i][i][k] = ori_cost[i][i][j] + cost[j][j][k];
                            changed = true; 
                        }
                    }
                }               
            }
        }
        if(!changed){
            stable = true;
            break;
        }
        cost = tmp;
        printf("Step %d\n", step++);
        for(int i=0;i<n;i++){
            printf("Node %c:\n", ('A'+i));
            printf("     ");
            for(int j=0;j<n;j++){
                printf("%4c", ('A'+j));
            }
            printf("\n");
            for(int j=0;j<n;j++){
                if(adj[i][j]){
                    printf("%4c ", ('A'+j));
                    for(int k=0;k<n;k++){
                        if(cost[i][j][k] == INF){
                            printf("%4s", "INF");
                        } else {
                            printf("%4d", cost[i][j][k]);
                        }
                    }
                    printf("\n");
                }
            }
            printf("\n");
        }
    }
}