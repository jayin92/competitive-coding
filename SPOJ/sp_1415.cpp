// FIXME: TIME LIMIT EXCEED, current time 30 sec, ideal time 5 sec
// TODO: need prev to solve the problem of move the last person in queue
/*
test data:
6 4
0 4 3
0 6 5
1 2 5
1 6 5 

10 4
1 1 2
1 2 3
1 3 4
1 4 5
0 1 10
1 5 10
0 5 10
*/
#define MAX 1000005
#include <iostream>
using namespace std;
struct Player
{
    Player* nxt = nullptr;
    Player* prev = nullptr;
    Player* parent;
    unsigned int team;
    unsigned int id;
    bool head = 1;
    bool end = 1;
};

int main(){
    int n, m, t, a, b;
    Player* team[MAX];
    Player* team_end[MAX];
    Player player[MAX];

    scanf("%d %d", &n, &m);    
    for (int i = 1; i <= n; i++){
        player[i].id = i;
        player[i].parent = &player[i];
        player[i].team = i;
        player[i].nxt = nullptr;
        player[i].prev = nullptr;
        team_end[i] = &player[i];
        team[i] = &player[i];
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &t, &a, &b);
        if(t == 0){
             if(player[a].head){
                 team[player[a].team] = player[a].nxt;
             }
             if(player[a].end){
                 team_end[a] = player[a].prev;
                 if(player[a].prev != nullptr){
                     team_end[a] -> nxt = nullptr;
                 }
             }
             if(!player[a].head){
                 player[a].prev -> nxt = player[a].nxt;
             }
             if(!player[b].end){
                 player[b].nxt -> prev = &player[a]; //if b is in the middle
             } else {
                 player[b].end = 0;
                 player[a].end = 1;
             }
             team_end[player[b].parent -> team] = &player[a];

             player[a].parent = player[b].parent;
             player[a].head = 0;
             player[a].team = player[b].team;

             player[a].nxt = player[b].nxt;
             player[a].prev = &player[b];
             player[b].nxt = &player[a];
            //  team_end[a] -> nxt = nullptr;
            //  team_end[b] -> nxt = nullptr;
            //  team[a] -> prev = nullptr;
            //  team[b] -> prev = nullptr;
        } else {
            if(team[a] == nullptr){
                continue;
            } else {
                if(team[b] == nullptr){
                    team[a] -> head = 1;
                    team[b] = team[a];
                } else {
                    team[a] -> head = 0;
                }

                if(team_end[b] != nullptr){
                    team_end[b] -> nxt = team[a];
                    team[a] -> prev = team_end[b];
                }
                team_end[b] = team_end[a];
                team[a] -> parent = team[b] -> parent;
                team[a] -> team = b;
                team[a] = nullptr;
                team_end[a] = nullptr;

            }
        }
    }
 
    for(int i=1;i<=n;i++){
        printf("#%d: ", i);
        Player* head = team[i];
        if(head == nullptr){
            printf("\n");
            continue;
        }
        while(head -> nxt != nullptr){
            printf("%d ", head -> id);
            head = head -> nxt;
        }
        printf("%d\n", head -> id);
    } 


 }