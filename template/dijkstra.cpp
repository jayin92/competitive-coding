// djisktra with priority queue and memory optimize

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair


const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
vector<vector<pll>> w;
vector<ll> d;
vector<int> parent;

void dijkstra(int src){
    // vector<bool> visit(n+1, false);
    priority_queue<pll, vector<pll>, greater<pll>> pq; // first: weight, second: vertex
    for(int i=1;i<n;i++){
        pq.push(mp(INF, i));
    }
    d[src] = 0;
    parent[src] = src;
    while(!pq.empty()){
        pll edge = pq.top();
        pq.pop();
        ll u = edge.second;
        cout << u << endl;
        for(auto i:w[u]){
            ll w = i.second;
            ll v = i.first;
            ll alt = d[u] + i.second;
            if(alt < d[v]){
                d[v] = alt;
                parent[v] = u;
                pq.push(mp(alt, v));
            }
        }
    }
}

int main () {

    cin >> n >> m;
    w.resize(n+1);
    d.resize(n+1, INF);
    parent.resize(n+1, -1);
    ll a, b, tmp;
    for(int i=0;i<m;i++){
        cin >> a >> b >> tmp;
        w[a].pb(mp(b, tmp));
        w[b].pb(mp(a, tmp));
    }
    dijkstra(0); // source = 1
    vector<int> ans;
    int cur;
    if(d[n-1] != INF){ // if d[n] = INF, there is no shortest path from vertex 1 to vertex n
        cur = n-1;
        while(cur != 0){
            ans.push_back(cur);
            cur = parent[cur];
        }
        ans.push_back(0);
        int sz = ans.size();
        for(int i=sz-1;i>=0;i--){
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    

    return 0;
}