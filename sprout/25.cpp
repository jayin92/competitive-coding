#include<bits/stdc++.h>

using namespace std;

struct node{
    node* nxt = nullptr;
    int id;
};

vector<node*> front;
vector<node*> rear;
int n, m, a, b;

void print(){
    for(int i=1;i<=n;i++){
        node* cur = front[i];
        printf("queue %d: ", i);
        if(cur == nullptr || rear[i] == nullptr){
            cout << "empty" << endl;
            continue; 
        }
        while(cur -> nxt != nullptr){
            cout << cur -> id << " ";
            cur = cur -> nxt;
        }
        cout << cur -> id << endl;
    }    
}

int main(){
    cin >> n >> m;
    string s;
    front.resize(n+1, nullptr);
    rear.resize(n+1, nullptr);
    while(m--){
        cin >> s;
        if(s == "ADD"){
            cin >> a >> b;
            node* tmp = new node;
            tmp -> id = b;
            if(front[a] == nullptr){
                front[a] = tmp;
            }
            if(rear[a] == nullptr){
                rear[a] = tmp;
            } else {
                rear[a] -> nxt = tmp;
                rear[a] = tmp;
            }
        } else if(s == "LEAVE"){
            cin >> a;
            if(front[a] == nullptr){
                printf("queue %d is empty!\n", a);
            } else {
                front[a] = front[a] -> nxt;
            }
        } else if(s == "JOIN"){
            cin >> a >> b;
            if(front[a] == nullptr){
                continue;
            }
            if(front[b] == nullptr){
                front[b] = front[a];
                rear[b] = rear[a];
            } else {
                rear[b] -> nxt = front[a];
                rear[b] = rear[a];                
            }
            front[a] = rear[a] = nullptr;
        }
    }
    print();
}