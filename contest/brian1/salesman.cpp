#include <bits/stdc++.h>

using namespace std;

int maze[105][105];
int n, m;
bool con = false;
// void go(int i, int j, bool diff){
//     if(i > n || j > m) return;
//     if(i == n && j == m){
//         if(diff == true && con == false) con = true;
//         return;
//     }
//     if(maze[i+1][j] == maze[i][j+1]){
//         con = true;
//         return;
//     } else {
//         if(diff == false){
//             go(i+1, j, false);
//             go(i, j+1, false);
//         } else {
//             go(i+1, j, true);
//             go(i, j+1, true);
//         }
//     }

// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        con = false;
        cin >> n >> m;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                cin >> maze[i][j];
            }
        }
        for(int i=1;i<=n-1;i++){
            if(con) break;
            for(int j=1;j<=m-1;j++){
                if(maze[i+1][j] == maze[i][j+1]){
                    con = true;
                    break;
                }
            }
        }
        if(con) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}