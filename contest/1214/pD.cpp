#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    n--;m--;
    bool a[n][m];
    char temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> temp;
            if(temp == '#') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    int temp = 0;
    if(a[0][1] == 0) temp++;
    if(a[1][0] == 0) temp++;
    if(temp == 2){
        cout << 0 << endl;
    }
}