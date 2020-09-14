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
const ll MAXN = 40;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


ll a[MAXN][MAXN];
ll r[MAXN][MAXN];
ll c[MAXN][MAXN];
ll dp[MAXN][MAXN][MAXN][MAXN];
int n, m;

ll solve(int x1, int y1, int x2, int y2){
    if(x1 == x2 || y1 == y2 || x1 == n || y1 == m || x2 == 0 || y2 == 0) return 0;
    if(dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
    ll res = INF;
    debug(x1, y1, x2, y2);
    for(int i=x1;i<x2;i++){
        for(int j=y1;j<y2;j++){
            ll tmp = a[i][j] * (c[i][y2-1] - (y1 == 0 ? 0 : c[i][y1 - 1]) + r[x2-1][j] - (x1 == 0 ? 0 : r[x1 - 1][j]) - a[i][j]);
            if(tmp >= res) continue;
            tmp += solve(x1, y1, i, j);
            if(tmp >= res) continue;
            tmp += solve(i+1, y1, x2, j);
            if(tmp >= res) continue; 
            tmp += solve(x1, j+1, i, y2);
            if(tmp >= res) continue;
            tmp += solve(i+1, j+1, x2, y2);
            if(tmp >= res) continue;
            res = min(res, tmp);
            debug(x1, y1, x2, y2, res);
        }
    }
    if(res == INF){
        return 0;
    } else {        
        return dp[x1][y1][x2][y2] = res;
    }
}


/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    REP(i, n){
        REP(j, m){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        c[i][0] = a[i][0];
        for(int j=1;j<m;j++){
            c[i][j] = c[i][j-1] + a[i][j];
        }
    }
    for(int j=0;j<m;j++){
        r[0][j] = a[0][j];
        for(int i=1;i<n;i++){
            r[i][j] = r[i-1][j] + a[i][j];
        }
    }

    cout << solve(0, 0, n, m) << endl;
    

    return 0;
}