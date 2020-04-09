int par[1505];
int m, r, cnt, gr; // count, group

void initialize(int n){
    m = n;
    r = n * (n - 1) / 2;
    gr = n;
    cnt = 1;
    for(int i=0;i<m;i++) par[i] = -1;
}

int hasEdge(int a, int b){
    if(gr < 2){
        if(par[a] == -1 && par[b] == -1){
            par[a] = par[b] = a;
        } else if(par[a] == par[b]){
            gr++;
        } else if(par[a] == -1 && par[b] != -1){
            par[a] = par[b];
        } else if(par[a] != -1 && par[b] == -1){
            par[b] = par[a];
        } else {
            int tmp = par[a];
            for(int i=0;i<m;i++){
                if(par[i] == tmp) par[i] = par[b];
            }
        }
        gr --;
        cnt ++;
        return 1;
        
    } else {    
        if(par[a] != par[b]) return 0;
        else return 1;
        cnt ++;
    }
}