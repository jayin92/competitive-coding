#include <iostream>
#include <queue>

using namespace std;

struct Point{
    int l, r, c;
    long long step = 0;
};
Point make(int l, int r, int c, int step){
    Point tmp;
    tmp.l = l; tmp.r = r; tmp.c = c;tmp.step = step;
    return tmp;
}
bool operator==(const Point& rhs, const Point& lhs){
    if(rhs.l == lhs.l && rhs.r == lhs.r && rhs.c == lhs.c){
        return true;
    }

    return false;
}

int l, r, c;
int m[40][40][40];
Point start;
Point end_;

vector<Point> adj(Point s){
    vector<Point> a;
    if(s.l - 1 >= 0 && m[s.l - 1][s.r][s.c] != 0){
        a.push_back(make(s.l - 1, s.r, s.c, 0));
    } 
    if(s.l + 1 < l && m[s.l + 1][s.r][s.c] != 0){
        a.push_back(make(s.l + 1, s.r, s.c, 0));
    }
    if(s.r + 1 < r && m[s.l][s.r + 1][s.c] != 0){
        a.push_back(make(s.l, s.r + 1, s.c, 0));
    }
    if(s.r - 1 >= 0 && m[s.l][s.r - 1][s.c] != 0){
        a.push_back(make(s.l, s.r - 1, s.c, 0));
    }
    if(s.c + 1 < c && m[s.l][s.r][s.c + 1] != 0){
        a.push_back(make(s.l, s.r, s.c + 1, 0));
    }
    if(s.c - 1 >= 0 && m[s.l][s.r][s.c - 1] != 0){
        a.push_back(make(s.l, s.r, s.c - 1, 0));
    }

    return a;
}

int bfs(Point start){
    queue<Point> que;
    bool vis[l][r][c];
    for(int i=0;i<l;i++){
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                vis[i][j][k] = false;
            }
        }
    }
    
    que.push(start);vis[start.l][start.r][start.c] = true;
    while(!que.empty()){
        Point u = que.front(); que.pop();
        if(u == end_){
            return u.step;
        }
        for(auto v: adj(u)){
            if(!vis[v.l][v.r][v.c]){
                vis[v.l][v.r][v.c] = true;
                que.push(make(v.l, v.r, v.c, u.step+1));
            }
        }
    }
    return -1;
}

int main(){
    int res;
    while(true){
        cin >> l >> r >> c;
        if(!l && !r && !c) break;
        char tmp;
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    cin >> tmp;
                    if(tmp == 'S'){
                        start.l = i;start.r = j;start.c = k;
                        m[i][j][k] = 2;
                    } else if(tmp == 'E'){
                        end_.l = i;end_.r = j;end_.c = k;
                        m[i][j][k] = 3;
                    } else if(tmp == '#'){
                        m[i][j][k] = 0;
                    } else if(tmp == '.'){
                        m[i][j][k] = 1;
                    }
                }
            }
        }
        res = bfs(start);
        if(res != -1){
            cout << "Escaped in " << res << " minute(s)." << endl;
        } else {
            cout << "Trapped!" << endl;       
        }
    }        
}