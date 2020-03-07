struct stack {
    int a[5001];
    int top_ = -1;
    int size = 0;
    bool empty(){
        return size == 0;
    }
    int top(){
        return a[top_];
    }
    void push(int x){
        a[top_ + 1] = x;
        top_ ++;
        size ++;
    }
    void pop(){
        top_ --;
        size --;
    }
};


void solve(int N, int order[]){
    int n = N;
    stack ri;
    stack le;
    for(int i=1;i<=n;i++){
        ri.push(i);
        push_train();
    }
    while(!ri.empty()){
        le.push(ri.top());
        ri.pop();
        move_station_1_to_2();
    }
    for(int i=0;i<n;i++){
        while(!le.empty()){
            if(le.top() == order[i]){
                le.pop();
                pop_train();
                break;
            } else {
                ri.push(le.top());
                le.pop();
                move_station_2_to_1();
            }
        }
        while(!ri.empty()){
            le.push(ri.top());
            ri.pop();
            move_station_1_to_2();
        }
    }
}