#include <bits/stdc++.h>

using namespace std;

int n, m;
bool findd;

void dfs(vector<vector<int>> &a, int x, int y, int sum, int step, vector<vector<int>> &cnt_pos, vector<vector<int>> &cnt_neg){
    if(findd || x < 1 || y < 1) return;
    sum += a[x][y];
    if(x == 1 && y == 1 && sum == 0){
        findd = true;
        return;
    }
    if(sum >= 0){
        int tmp = cnt_neg[x][y] - (a[x][y] == -1);
        if(tmp < sum) return; 
    } else {
        int tmp = cnt_pos[x][y] - (a[x][y] == 1);
        if(tmp < sum) return;
    }     
    dfs(a, x-1, y, sum, step+1, cnt_pos, cnt_neg);
    dfs(a, x, y-1, sum, step+1, cnt_pos, cnt_neg);
}

void solve(){
    cin >> n >> m;
    findd = false;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i+1][j+1];
        }
    }
    if(n+m-1 % 2 == 1){
        cout << "NO" << endl;
        return;
    }
    vector<vector<int>> cnt_pos(n+1, vector<int>(m+1, 0));
    vector<vector<int>> cnt_neg(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt_pos[i][j] = cnt_pos[i-1][j] + cnt_pos[i][j-1] - cnt_pos[i-1][j-1];
            cnt_neg[i][j] = cnt_neg[i-1][j] + cnt_neg[i][j-1] - cnt_neg[i-1][j-1];
            if(a[i][j] == 1){
                cnt_pos[i][j] ++;
            } else {
                cnt_neg[i][j] ++;
            }
        }
    }    
    dfs(a, n, m, 0, 1, cnt_pos, cnt_neg);
    if(findd){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}