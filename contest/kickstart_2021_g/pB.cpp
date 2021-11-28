
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

void solve(int t){
    int k;
    cin >> k;
    vector<ll> x(2*k);
    vector<ll> y(2*k);
    vector<ll> x1(k);
    vector<ll> x2(k);
    vector<ll> y1(k);
    vector<ll> y2(k);

    for(int i=0;i<k;i++){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x[2*i] = x1[i];
        x[2*i+1] = x2[i];
        y[2*i] = y1[i];
        y[2*i+1] = y2[i];
    }
    sort(ALL(x1));
    sort(ALL(x2));
    sort(ALL(y1));
    sort(ALL(y2));
    sort(ALL(x));
    sort(ALL(y));
    reverse(ALL(x1));
    reverse(ALL(y1));
    vector<ll> r(k+1, 0);
    vector<ll> l(k+1, 0);
    for(int i=1;i<=k;i++){
        r[i] = r[i-1] + x2[i-1];
        l[i] = l[i-1] + x1[i-1];
    }
    
    debug(x, y);
    debug(l, r);
    int ansx, ansy;
    ansx = ansy = 0;
    ll tmp = INF;
    debug(x1);
    for(int i=0;i<2*k;i++){
        ll res = 0;
        ll idx = max((ll)0, (ll)(upper_bound(ALL(x2), x[i]) - x2.begin()));
        res += idx * x[i] - r[idx];
        idx = max((ll)0, (ll)(upper_bound(ALL(x1), x[i], greater<ll>()) - x1.begin()));
        debug(idx, x[i], res);
        res += l[idx] - idx * x[i];
        if(tmp > res){
            tmp = res;
            ansx = x[i];
        }
    }
    for(int i=1;i<=k;i++){
        r[i] = r[i-1] + y2[i-1];
        l[i] = l[i-1] + y1[i-1];
    }
   
    tmp = INF;
    for(int i=0;i<2*k;i++){
        ll res = 0;
        ll idx = max(0LL, (ll)(upper_bound(ALL(y2), x[i]) - y2.begin()));
        res += idx * y[i] - r[idx];
        idx = max(0LL, (ll)(upper_bound(ALL(y1), y[i], greater<ll>()) - y1.begin()));
        res += l[idx] - idx * y[i];
        if(tmp > res){
            tmp = res;
            ansy = y[i];
        }
    }
    cout << "Case #" << t << ": ";
    cout << ansx << " " << ansy << endl;
    
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve(i);
    }

    return 0;
}