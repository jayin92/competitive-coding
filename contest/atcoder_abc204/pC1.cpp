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
const ll MAXN = 100005;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
vector<vector<int>> adj1;
vector<vector<int>> adj2;
vector<set<int>> dag;
vector<bool> vis;
vector<vector<bool>> con;
vector<vector<bool>> con1;
vector<vector<int>> a_;
vector<vector<int>> scc;
vector<int> scc_idx;
vector<ll> scc_sum;
stack<int> s;

int n, m;

void fillorder(int cur){
    vis[cur] = true;
    for(auto i:adj1[cur]){
        if(vis[i] == false){
            fillorder(i);
        }
    }

    s.push(cur);
}


void dfs(int cur, int idx){
    vis[cur] = true;
    scc[idx].push_back(cur);
    scc_idx[cur] = idx;
    for(auto i:adj2[cur]){
        if(!vis[i]){
            dfs(i, idx);
        }
    }
}

void SCC(){
    fill(ALL(vis), false);
    for(int i=0;i<n;i++){
        if(!vis[i]) fillorder(i);
    }

    fill(ALL(vis), false);
    int idx = 0;
    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(!vis[v]){
            dfs(v, idx);
            idx ++;
        }
    }
}

void makeDAG(){
    for(int i=0;i<n;i++){
        for(auto j:adj1[i]){
            if(scc_idx[i] != scc_idx[j]){
                dag[scc_idx[i]].insert(scc_idx[j]);
            }
        }
    }
}

ll ans;

void dag_dfs_1(int cur, int prev, ll sum){
    ll sz = scc[cur].size();
    if(prev != -1 && scc_sum[cur] != 0){
        sum -= sz;
    }
    scc_sum[cur] += sum;
    for(auto i:dag[cur]){
        if(i != prev){
            dag_dfs_1(i, cur, sum+sz);
        }
    }
}

void dag_dfs_2(int cur){
    vis[cur] = true;
    ll sz = scc[cur].size();
    debug(scc_sum[cur]);
    ans += sz * scc_sum[cur] + sz * sz;
    debug(ans, cur);
    assert(ans >= 0);
    for(auto i:dag[cur]){
        if(!vis[i]){
            dag_dfs_2(i);
        }
    }
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    ans = 0;
    cin >> n >> m;
    adj1.resize(n);
    adj2.resize(n);
    vis.resize(n, false);
    con.resize(n, vector<bool>(n, false));
    con1.resize(n, vector<bool>(n, false));
    scc.resize(n);
    scc_idx.resize(n);
    vector<int> ind(n, 0);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
        ind[b] ++;
    }
    
    SCC();
    debug(scc);

    // return 0;
    int sz = scc.size();
    dag.resize(sz);
    scc_sum.resize(sz, 0); 
    debug(scc_idx);

    makeDAG();
    

    set<int> s_;
    for(int i=0;i<sz;i++){
        s_.insert(i);
    }
    for(int i=0;i<sz;i++){
        for(auto j:dag[i]){
            s_.erase(j);
        }
    }
    debug(s_);

    for(auto i:s_){
        dag_dfs_1(i, -1, 0);
    }
    debug(scc_sum);
    fill(ALL(vis), false);

    for(int i=0;i<sz;i++){
       if(!vis[i]){
           dag_dfs_2(i);
       }
    }

    cout << ans << endl;
    debug(dag);
 
    return 0;
}