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

inline ll fast_mod(const ll input, const ll ceil) {
    // apply the modulo operator only when needed
    // (i.e. when the input is greater than the ceiling)
    return input >= ceil ? input % ceil : input;
    // NB: the assumption here is that the numbers are positive
}

vector<vector<ll>> dp;
vector<vector<ll>> pre;
ll ans;
void solve(string s, int pri){
    int sz = s.size();
    int first = s[0] - '0';
    if(first < pri){
        return;
    }
    if(sz == 1){
        ans += first - pri + 1;
        ans = fast_mod(ans, MOD);
        return;
    } else {
        ans += pre[sz][first-1] - pre[sz][pri-1];
        ans += MOD;
        ans = fast_mod(ans, MOD);
        solve(s.substr(1, sz-1), first);
    }
}
/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int n = 1e5 + 5;
    dp.resize(n, vector<ll>(10, 0));
    pre.resize(n, vector<ll>(10, 0));
    for(int i=1;i<=9;i++){
        dp[1][i] = 1;
        if(i == 1){
            pre[1][i] = dp[1][i];
        } else {
            pre[1][i] = dp[1][i] + pre[1][i-1];
        }
    }
    for(int i=2;i<n;i++){
        for(int j=1;j<=9;j++){
            dp[i][j] += pre[i-1][9] - pre[i-1][(j-1 == 0 ? 0 : j-1)];
            dp[i][j] += MOD;
            dp[i][j] = fast_mod(dp[i][j], MOD);
            if(j == 1){
                pre[i][j] = dp[i][j];
            } else {
                pre[i][j] = dp[i][j] + pre[i][j-1];
            }
            pre[i][j] = fast_mod(pre[i][j], MOD);
        }
        
    }
    // debug(dp);
    string s;
    while(!cin.eof() && cin >> s){
        ans = 0;
        int sz = s.size();
        int first = s[0] - '0';
        if(sz == 1){
            ans += first;
        } else {
            for(int i=1;i<sz;i++){
                ans += pre[i][9];
                ans = fast_mod(ans, MOD);
            }
            ans += pre[sz][(first-1 == 0 ? 0 : first-1)];
            ans = fast_mod(ans, MOD);
            solve(s.substr(1, sz-1), first);
        }
        ans += MOD;
        ans = fast_mod(ans, MOD);
        cout << ans << endl;
    }
    return 0;
}