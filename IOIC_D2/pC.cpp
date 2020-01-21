#include <bits/stdc++.h>
#define mod 10e9+7

using namespace std;

int main(){
    int n, k;
    vector<int> adj[n];
    int a, b;
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        adj[a].push_back(b);adj[b].push_back(a);
    }
    
}