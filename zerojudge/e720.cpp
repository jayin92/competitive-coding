#include <bits/stdc++.h>
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
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
#ifdef jayinnn
#define TIME(i) Timer i(#i)
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,deque<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
class Timer {
private:
    string scope_name;
    chrono::high_resolution_clock::time_point start_time;
public:
    Timer (string name) : scope_name(name) {
        start_time = chrono::high_resolution_clock::now();
    }
    ~Timer () {
        auto stop_time = chrono::high_resolution_clock::now();
        auto length = chrono::duration_cast<chrono::microseconds>(stop_time - start_time).count();
        double mlength = double(length) * 0.001;
        debug(scope_name, mlength);
    }
};
#else
#define TIME(i)
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
#endif

const ll MOD = 1000000007;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int iNF = 0x3f3f3f3f;
const ll MAXN = 2005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


vector<vector<int>> adj(MAXN, vector<int>(MAXN, 0));
vector<int> vis(MAXN, 0);
vector<int> low(MAXN, 0);
vector<int> stk(MAXN);
vector<int> contract(MAXN);
vector<ll> cnt(MAXN, 0);
vector<pii> bri;
vector<vector<int>> bcc(MAXN);
ll ans = 0;
int t = 0;
int top = 0;

int n, m;
void DFS(int i, int p)
{
        
    vis[i] = low[i] = ++t;
    stk[top++] = i;   // push i
 
    for (int j=0; j<n; ++j){
        if (adj[i][j])
        {
            // tree edge
            if (!vis[j])
                DFS(j, i);
 
            // tree/back edge
            if (!(j == p && adj[i][j] == 1)){
                low[i] = min(low[i], low[j]);
                if(low[j] > vis[i]){
                    debug(j, i);
                    // debug(contract[i], contract[j]);
                    bri.pb({i, j});
                    // bcc[contract[i]].pb(contract[j]);
                    // bcc[contract[j]].pb(contract[i]);
                }
            }
        }
    }
 
    // 形成BCC。
    // BCC裡面，最早拜訪的點是i點。
    if (vis[i] == low[i])
    {
//      cout << "block:";
        int j;
        do {
            j = stk[--top];   // pop j
//          cout << j;
            contract[j] = i;    
        } while (i != j);
    }
}

ll dfs2(int cur, int u, int v){
    debug(cur, u, v);
    ll tmp = cnt[cur];
    debug(cur, bcc[cur]);
    for(auto i: bcc[cur]){
        if(i != u and i != v){
            tmp += dfs2(i, cur, v);
        }
    }
    return tmp;
}

void solve(){
    cin >> n >> m;
    int u, v;
    vector<pii> edge;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        adj[u][v] ++;
        adj[v][u] ++;
        edge.pb({u, v});
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            DFS(i, i);
        }
    }
    for(int i=0;i<n;i++){
        cnt[contract[i]]++;
    }

    fill(ALL(vis), false);
    if(bri.size() == 0){
        cout << 0 << endl;
        return ;
    }
    int sz = bri.size();
    for(int i=0;i<sz;i++){
        u = contract[bri[i].X];
        v = contract[bri[i].Y];
        bcc[u].pb(v);
        bcc[v].pb(u);
        bri[i] = {u, v};
    }
    for(auto i: bri){
        u = i.X;
        v = i.Y;
        ll x = dfs2(u, u, v);
        ll y = dfs2(v, v, u);
        debug(x, y, u, v);
        ans = max(ans, x*y);
    }
    cout << ans << endl;



}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    
    solve();
    

    return 0;
}