#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<double,double> pdd;
#define SQ(i) ((i)*(i))
#define MEM(a, b) memset(a, (b), sizeof(a))
#define SZ(i) int(i.size())
#define FOR(i, j, k, in) for (int i=j ; i<(k) ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=(k) ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REP1(i,j) FOR(i, 1, j+1, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define ALL(_a) _a.begin(),_a.end()
#define mp make_pair


const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll iNF = 0x3f3f3f3f;


int n = 26;
vector<vector<pll>> w(26);
vector<int> parent[3];

void dijkstra(int src, vector<ll> &d, int ii){
    // vector<bool> visit(n+1, false);
    priority_queue<pll, vector<pll>, greater<pll>> pq; // first: weight, second: vertex
    for(int i=0;i<n;i++){
        pq.push(mp(INF, i));
    }
    d[src] = 0;
    parent[ii][src] = src;
    while(!pq.empty()){
        pll edge = pq.top();
        pq.pop();
        ll u = edge.second;
        for(auto i:w[u]){
            // ll w = i.second;
            ll v = i.first;
            ll alt = d[u] + i.second;
            if(alt < d[v]){
                d[v] = alt;
                parent[ii][v] = u;
                pq.push(mp(alt, v));
            }
        }
    }
}


string route(int cur, int i){
    string res = "";
    while(cur != -1){
        if(parent[i][cur] == cur){
            break;
        }
        res += 'A' + cur;
        res += " ";
        cur = parent[i][cur];
    }

    // res += 'A' + cur;
    reverse(res.begin(), res.end()-1);

    return res.substr(0, res.size()-1);
}

int con(string a){
    return a[0] - 'A';
}

/********** Good Luck :) **********/
int main () {
    vector<ll> d[3];

    d[0].resize(26, INF);
    d[1].resize(26, INF);
    d[2].resize(26, INF);
    parent[0].resize(26, -1);
    parent[1].resize(26, -1);
    parent[2].resize(26, -1);

    int beg, end, m1, m2;
    string a, b, c, dd;
    cin >> a >> b >> c >> dd;
    beg = con(a);
    end = con(b);
    m1 = con(c);
    m2 = con(dd);
    // debug(beg, m1, m2, end);
    string s;
    cin.ignore();
    while(getline(cin, s)){
        // if(s.size() == 0) break;
        int u = con(s.substr(0, 1));
        int v = con(s.substr(5, 1));
        int ww = stoi(s.substr(8, s.size()));
        w[u].push_back(mp(v, ww));
    }

    dijkstra(beg, d[0], 0);
    dijkstra(m1, d[1], 1);
    dijkstra(m2, d[2], 2);
    ll a1 = d[0][m1] + d[1][m2] + d[2][end];
    ll a2 = d[0][m2] + d[2][m1] + d[1][end];
    if(a1 > a2){
        string r = route(m2, 0) + " " + route(m1, 2) + " " + route(end, 1);
        cout << a << " " << r << endl;        
        cout << a2 << endl;
    } else {
        string r = route(m1, 0) + " " + route(m2, 1) + " " + route(end, 2);
        cout << a << " " << r << endl;  
        cout << a1 << endl;
    }
    

    return 0;
}