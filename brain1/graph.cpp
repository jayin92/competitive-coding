#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, u, v, w;
    cin >> n >> m;
    int g[n+1][n+1] = {0};
    for(int i=0;i<n;i++){
        cin >> u >> v >> w;
        g[u][v] = w;
        g[v][u] = w;
    }
    
}