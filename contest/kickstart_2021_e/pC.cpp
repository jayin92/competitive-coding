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

int n, m;
int ans = 0;
vector<vector<int>> g;
queue<pii> pos;

void fill(){
    pii cur = pos.front();
    pos.pop();
    int hs, he;
    int vs, ve;
    hs = he = vs = ve = 0;
    int x = cur.X;
    int y = cur.Y;
    for(int i=x;i>=0;i--){
        if(g[i][y] == -2){
            hs = i+1;
            break;
        }
    }
    for(int i=x;i<=n+1;i++){
        if(g[i][y] == -2){
            he = i-1;
            break;
        }
    }
    for(int i=y;i>=0;i--){
        if(g[x][i] == -2){
            vs = i+1;
            break;
        }
    }
    for(int i=y;i<=m+1;i++){
        if(g[x][i] == -2){
            ve = i-1;
            break;
        }
    }
    debug(x, y, vs, ve, hs, he);
    int dv = (ve - vs + 1);
    int dh = (he - hs + 1);
    
    if(g[x][vs + (dv - 1 - (y - vs))] == -1){
        ans ++;
        g[x][vs + (dv - 1 - (y - vs))] = g[x][y];
        pos.push({x, vs + (dv - 1 - (y - vs))});
    }
    if(g[hs + (dh - 1 - (x - hs))][y] == -1){
        ans ++;
        g[hs + (dh - 1 - (x - hs))][y] =  g[x][y];
        pos.push({hs + (dh - 1 - (x - hs)), y});
    }    
}

void solve(int t){
    cin >> n >> m;
    ans = 0;
    for(int i=0;i<=n;i++){
        g[i][0] = -2;
        g[i][m+1] = -2;
    }
    for(int j=0;j<=m;j++){
        g[0][j] = g[n+1][j] = -2;
    }

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            if(s[j] == '.'){
                g[i+1][j+1] = -1;
            } else if(s[j] == '#'){
                g[i+1][j+1] = -2;
            } else {
                g[i+1][j+1] = s[j] - 'A';
                pos.push({i+1, j+1});
            }
        }
    }
    cout << "Case #" << t + 1 << ": ";
    while(!pos.empty()){
        fill();
    }
    cout << ans << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j] == -1){
                cout << ".";
            } else if(g[i][j] == -2){
                cout << "#";
            } else {
                cout << (char)(g[i][j] + 'A');
            }
        }
        cout << endl;
    }
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    g.resize(1005, vector<int>(1005));
    int t;
    cin >> t;
    REP(i, t){
        solve(i);
    }
    



    return 0;
}