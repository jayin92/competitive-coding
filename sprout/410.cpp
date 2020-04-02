#include <iostream>

using namespace std;

int par[1505];
int cnt, r, m, group;
int a_ = -1, b_ = -1;

void initialize(int n){
    for(int i=0;i<n;i++) par[i] = -1;

    r = n * (n - 1) / 2;
    cnt = 1;
    m = n;
    group = n;
} 

int hasEdge(int a, int b){
    if(a == a_ && b == b_) return 1;
    if(group > 2){
        if(par[a] == -1 && par[b] == -1){
            par[a] = par[b] = a;
        } else if(par[a] == par[b]){
            group ++;
        } else if(par[a] != -1 && par[b] == -1){
            par[b] = par[a];
        } else if(par[a] == -1 && par[b] != -1){
            par[a] = par[b];
        } else {
            int tmp = par[b];
            for(int i=0;i<m;i++){
                if(par[i] == tmp){
                    par[i] = par[a];
                }
            }
        }
        cnt ++;
        group --;
        return 1;
    } else {
        if(cnt == r){
            return 0;
        } else {
            return 0;
        }
    }
}

int main(){
    int a, b;
    int n_;
    cin >> n_;
    initialize(n_);
    while(true){
        cin >> a >> b;
        cout << hasEdge(a, b) << endl;
    }
}