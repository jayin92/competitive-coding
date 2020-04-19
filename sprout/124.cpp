#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;


void solve(int n, int x, int y);
void solve1(int n, int x, int y);
// void print(int sz);


int s;
int a[1030][1030];
void solve(int n, int x, int y){
    s = n;
    memset(a, 0, (n+1) * (n+1) * sizeof(int));
    a[x][y] = 1;
    solve1(n, 1, 1);

}

void solve1(int n, int x, int y){
    // print(s);
    if(n == 2){
        vector<pair<int, int>> ans;
        for(int i=x;i<x+n;i++){
            for(int j=y;j<y+n;j++){
                if(a[i][j] == 0){
                    ans.emplace_back(i, j);
                }
            }
        }
        Report(ans[0].X, ans[0].Y, ans[1].X, ans[1].Y, ans[2].X, ans[2].Y);
    } else {
        vector<pair<int, int>> b;
        bool flag = true;
        for(int i=x;i<x+n/2;i++){
            for(int j=y;j<y+n/2;j++){
                if(a[i][j] == 1){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) b.emplace_back(x+n/2-1, y+n/2-1);
        flag = true;
        for(int i=x;i<x+n/2;i++){
            for(int j=y+n/2;j<y+n;j++){
                if(a[i][j] == 1){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) b.emplace_back(x+n/2-1, y+n/2);
        flag = true;
        for(int i=x+n/2;i<x+n;i++){
            for(int j=y;j<y+n/2;j++){
                if(a[i][j] == 1){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) b.emplace_back(x+n/2, y+n/2-1);
        flag = true;
        for(int i=x+n/2;i<x+n;i++){
            for(int j=y+n/2;j<y+n;j++){
                if(a[i][j] == 1){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) b.emplace_back(x+n/2, y+n/2);
        flag = true;
        for(auto i:b) a[i.X][i.Y] = 1;
        for(int i=x;i<x+n;i+=n/2){
            for(int j=y;j<y+n;j+=n/2){
                solve1(n/2, i, j);
            }
        }
        Report(b[0].X, b[0].Y, b[1].X, b[1].Y, b[2].X, b[2].Y);        
    }

}

void Report(int x1, int y1, int x2, int y2, int x3, int y3){
    // printf("Report(%d, %d, %d, %d, %d, %d)\n", x1, y1, x2, y2, x3, y3);
    return;
}


void print(int sz){
    for(int i=1;i<=sz;i++){
        for(int j=1;j<=sz;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    solve(4,3,4);
}
