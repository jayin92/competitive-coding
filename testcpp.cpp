// FIXME: TIME LIMIT EXCEED, current time 30 sec, ideal time 5 sec
// TODO: add team_end array
/*
test data:
6 4
0 4 3
0 6 5
1 2 5
1 6 5 
*/
#define MAX 1005
#include <iostream>
using namespace std;

struct Player
{
    Player* nxt = nullptr;
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
	
	n = 1000;
	m = 1000;
    for (int i = 1; i <= n; i++){
        player[i].id = i;
        player[i].parent = &player[i];
        player[i].team = i;
        player[i].nxt = nullptr;
        team_end[i] = &player[i];
        team[i] = &player[i];
    }
    for(int i=0;i<m;i++){
    	t = 1;
    	a = i+1;
    	b = 0;
        if(t == 0){
             if(player[a].head){
                 team[player[a].team] = player[a].nxt;
             }
             if(player[b].end){
                 team_end[player[b].parent -> team] = &player[a];
                 player[b].end = 0;
                 player[a].end = 1;
             }
             player[a].parent = player[b].parent;
             player[a].head = 0;
             player[a].team = player[b].team;
             player[a].nxt = player[b].nxt;
             player[b].nxt = &player[a];
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
                } else {
                    team_end[b] = team_end[a];
                }
                team[a] -> parent = team[b] -> parent;
                team[a] -> team = b;
                team[a] = nullptr;
                team_end[a] = nullptr;
            }
        }
    }

    //print 
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