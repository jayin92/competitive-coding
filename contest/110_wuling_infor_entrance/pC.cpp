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

pii d[4] = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1}
}; 
// u, d, r, l

int ops[4] = {1, 0, 3, 2};
int order[4] = {1, 2, 0, 3};
int ans;

struct Dir{
    bool u, d, r, l;
};

pii add(pii a, pii b){
    pii res = {a.X + b.X, a.Y + b.Y};

    return res;
}

pii mul(pii a, int s){
    pii res = {s*a.X, s*a.Y};

    return res;
}

vector<vector<vector<bool>>> tmp;

void dfs(pii ori, pii cur, int idx, int step, int remain){
    int x = cur.X;
    int y = cur.Y;
    // debug(cur);
    
    if(remain == 0){
        if(ori == cur){
            ans ++;
            return;
        }
        idx ++;
        remain = step;
    }
    if(tmp[x][y][order[idx]]){
        dfs(ori, add(cur, d[order[idx]]), idx, step, remain - 1);
    } else {
        return;
    }
}

void solve(int t){
    int n, m;
    cin >> n >> m;
    char c;
    int x, y;
    vector<vector<vector<bool>>> g(n+2, vector<vector<bool>>(n+2, vector<bool>(4, false)));
    for(int i=0;i<m;i++){
        cin >> c >> x >> y;
        if(c == 'H'){
            g[x][y][2] = true;
            g[x][y+1][3] = true;
        } else {
            swap(x, y);
            g[x][y][1] = true;
            g[x+1][y][0] = true;
        }
    }

    cout << "Problem #" << t + 1 << endl;
    bool flag = true;
    for(int s=1;s<=n;s++){
        ans = 0;
        tmp = g;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dfs({i, j}, {i, j}, 0, s, s);
            }
        }
        if(ans != 0){
            flag = false;
            cout << "Size " << s << ":" << ans << endl;
        }
    }
    if(flag){
        cout << "No squares" << endl;
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