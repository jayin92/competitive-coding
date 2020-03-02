#include <iostream>

#define MAX 10005

using namespace std;

struct Player{
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

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        player[i].id = i;
        player[i].parent = &player[i];
        player[i].team = i;
        player[i].nxt = nullptr;
        player[i].prev = nullptr;
        team_end[i] = &player[i];
        team[i] = &player[i];
    }

    for(int i=0;i<m;i++){
        cin >> t >> a >> b;
        if(t == 0){
            if(player[a].head){
                team[player[a].team] = player[a].nxt;
                player[a].nxt -> prev = nullptr;
            }
            if(player[a].end){
                team_end[player[a].parent -> team] = player[a].prev;
                if(player[a].prev != nullptr){
                    player[a].prev -> nxt = nullptr;
                }
            }
            if(!player[a].head && !player[a].end){
                player[a].prev -> nxt = player[a].nxt;
                player[a].nxt -> prev = player[a].prev;
            }
            if(player[b].end){
                player[a].nxt = nullptr;
                player[a].end = 1;
                team_end[player[b].parent -> team] = &player[a];                
            } else {
                player[a].nxt = player[b].nxt;
                player[b].nxt -> prev = &player[a];
            }
            player[b].nxt = &player[a];
            player[a].prev = &player[b];

            player[a].parent = player[b].parent;
            player[a].team = player[b].team;
            player[a].head = 0;
        } else {
            if(team[a] == nullptr){
                continue;
            } else {
                Player* teamA_head;
                Player* teamA_end;
                teamA_head = new Player;
                teamA_end = new Player;
                teamA_head -> nxt = team[a] -> nxt;
                teamA_head -> prev = nullptr;
                teamA_head -> id = team[a] -> id;
                teamA_head -> head = team[a] -> head;
                teamA_head -> end = team[a] -> end;

                teamA_end -> nxt = nullptr;
                teamA_end -> prev = team_end[a] -> prev;
                teamA_end -> id = team_end[a] -> id;
                teamA_end -> head = team_end[a] -> head;
                teamA_end -> end = team_end[a] -> end;
                if(team[b] == nullptr){
                    team[b] = teamA_head;
                    team_end[b] = teamA_end;
                } else {
                    teamA_head -> head = 0;
                    team_end[b] -> nxt = teamA_head;
                    teamA_head -> prev = team_end[b];
                }
                team_end[b] = teamA_end;
                teamA_head -> parent = team[b] -> parent;
                teamA_head -> team = b;
                team[a] = nullptr;
                team_end[a] = nullptr;
                // player[a] 要換
                player[teamA_head -> id] = *teamA_head;
                player[teamA_end -> id] = *teamA_end;

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