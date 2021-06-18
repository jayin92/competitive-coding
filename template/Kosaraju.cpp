// same scc will number 

#include <bits/stdc++.h>

using namespace std;

const int N = 100; // # of vertex

vector<vector<int>> g; // graph
vector<vector<int>> r; // reversed graph
vector<int> order;
vector<int> scc(N);
vector<bool> vis(N);

void RevDfs(int cur){
    vis[cur] = true;
    for(int u: r[cur]){
        if(!vis[u]){
            RevDfs(u);
        }
    }
    order.push_back(cur); // topological order
}

void Dfs(int cur, int s){
    scc[cur] = s;
    for(int u: g[cur]){
        if(scc[u] == -1) Dfs(u, s);
    }
}

void Kosaraju(int n){
    fill(vis.begin(), vis.end(), false);
    fill(scc.begin(), scc.end(), -1);

    for(int i=0;i<n;i++){
        if(!vis[i]) RevDfs(i);
    }

    int n_scc = 0;
    for(int i=n-1;i>=0;i--){
        int cur = order[i];
        if(scc[cur] == -1){
            Dfs(cur, n_scc);
            n_scc++;
        }
    }
}

