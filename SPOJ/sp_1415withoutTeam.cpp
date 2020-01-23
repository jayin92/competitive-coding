#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

struct Player
{
    Player* nxt = nullptr;

    unsigned int team;
    unsigned int id;
    bool head = 1;
};

int main(){
    int n, m, t, a, b;
    
    cin >> n >> m;
    Player* team[n];
    Player player[n];
    for (int i = 1; i <= n; i++){
        player[i].id = i;
        player[i].team = i;
        player[i].nxt = nullptr;
        team[i] = &player[i];
    }
    for(int i=0;i<m;i++){
        cin >> t >> a >> b;
        if(t == 0){
             if(player[a].head){
                 team[player[a].team] = player[a].nxt;
             }
             player[a].head = 0;
             player[a].team = player[b].team;
             player[a].nxt = player[b].nxt;
             player[b].nxt = &player[a];
        } else {
            Player* teamA_current = team[a];
            Player* teamA_head = team[a];
            Player* teamB_current = team[b];
            if(teamA_head == nullptr){
                continue;
            } else {
                if(teamB_current == nullptr){
                    teamA_current -> head = 1;
                } else {
                    teamA_current -> head = 0;
                }
                while(teamA_current -> nxt != nullptr){
                    teamA_current -> team = b;                    
                }
                teamA_current -> team = b;
                while(teamB_current -> nxt != nullptr){
                    teamB_current = teamB_current -> nxt;
                }
                teamB_current -> nxt = teamA_head;
                team[a] = nullptr;               
            }
        }
    }

    //print 
    for(int i=1;i<=n;i++){
        cout << "#" << i << ": ";
        Player* head = team[i];
        if(head == nullptr){
            cout << endl;
            continue;
        }
        while(head -> nxt != nullptr){
            cout << head -> id << " ";
            head = head -> nxt;
        }
        cout << head -> id << endl;
    }
    
    
 }