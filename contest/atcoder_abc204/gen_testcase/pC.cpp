#include "testlib.h"

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int n = rnd.next(2000);
    int m = min(rnd.next(2000), n*(n-1));

    vector<int> p(n);
    vector<pair<int, int>> edge(m);
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(cnt == m) break;
            if(i != j){
                int t = rnd.next(10);
                if(t == 0){
                    edge[cnt++] = make_pair(i+1, j+1);
                } else if(t == 1){
                    edge[cnt++] = make_pair(j+1, i+1);
                }
            }
        }
        if(cnt == m) break;
    }
    shuffle(edge.begin(), edge.end());
    printf("%d %d\n", n, m);
    for(auto i:edge){
        printf("%d %d\n", i.first, i.second);
    }
    
}