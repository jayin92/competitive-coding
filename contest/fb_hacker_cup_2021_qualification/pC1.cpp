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
const ll MAXN = 55;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<ll> w(MAXN);
vector<vector<int>> adj(MAXN);
vector<ll> cnt(MAXN);
vector<int> child;
vector<int> p(MAXN);
vector<vector<int>> lca(MAXN, vector<int>(MAXN));
vector<bool> vis(MAXN);

ll ans;
int n;

int find(int x){
   
    return x == p[x] ? x : (p[x] = find(p[x]));
}

void dfs1(int pre, int cur, ll total){
    assert(total >= 0);
    if(cur != 1 and adj[cur].size() == 1){
        ans = max(ans, total+w[cur]);
        return;
    }
    for(auto i:adj[cur]){
        if(i != pre){
            dfs1(cur, i, total+w[cur]);
        }
    }
}

void dfs2(int pre, int cur, ll total){
    cnt[cur] = total + w[cur];
    if(cur != 1 and adj[cur].size() == 1){
        child.pb(cur);
        return;
    }
    for(auto i:adj[cur]){
        if(i != pre){
            debug(cur, i, pre);
            dfs2(cur, i, total+w[cur]);
        }
    }
}

void dfs3(int pre, int x){
    if(vis[x]) return;
    vis[x] = true;

    for(int i=1;i<=n;i++){
        if(vis[i]){
            lca[x][i] = lca[i][x] = find(i);
        }
    }

    for(auto i: adj[x]){
        if(i != pre){
            dfs3(x, i);
            p[i] = x;        
        }
    }
    
}


void solve(int t){
    cin >> n;
    for(int i=1;i<=n;i++){
        adj[i].clear();
        child.clear();
        cnt[i] = 0;
        p[i] = i;
        vis[i] = false;
    }
    for(int i=0;i<n;i++){
        cin >> w[i+1];
    }
    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cout << "Case #" << t+1 << ": ";
    if(adj[1].size() == 0){
        cout << w[1] << endl;
    } else if(adj[1].size() == 1){
        ans = w[1];
        dfs1(-1, 1, 0);
        cout << ans << endl;
    } else {
        dfs2(-1, 1, 0);
        dfs3(-1, 1);
        int sz = child.size();
        ll ans_ = 0;
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                int x = child[i];
                int y = child[j];
                int anc = lca[x][y];
                assert(lca[x][y] == lca[y][x]);
                if(anc == 1){
                    ll tmp = cnt[x] + cnt[y] - cnt[1];
                    if(tmp >= ans_){
                        ans_ = tmp;
                        debug(x, y, tmp);
                    }
                }                    
            }
        }
        cout << ans_ << endl;
    }

}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t;
    cin >> t;
    REP(i, t){
        solve(i);
    }

    return 0;
}