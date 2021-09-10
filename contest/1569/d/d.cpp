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
const ll MAXN = 1e6+5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<bool> v(MAXN, false);
vector<bool> h(MAXN, false);

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    fill(ALL(v), false);
    fill(ALL(h), false);
    ll vv = 0;
    ll hh = 0;
    ll both = 0;
    vector<pii> a(k);
    vector<ll> cntv(MAXN, 0);
    vector<ll> cnth(MAXN, 0);
    vector<ll> cntvv(MAXN, 0);
    vector<ll> cnthh(MAXN, 0);
    vector<ll> xl(MAXN, 0);
    vector<ll> xr(MAXN, 0);
    vector<ll> yl(MAXN, 0);
    vector<ll> yr(MAXN, 0);
    int tmp;
    REP(i, n){
        cin >> tmp;
        v[tmp] = true;
    }
    REP(i, m){
        cin >> tmp;
        h[tmp] = true;
    }
    REP(i, k){
        cin >> a[i].X >> a[i].Y;
        debug(a[i]);
        if(v[a[i].X]){
            if(h[a[i].Y]){
                both ++;
            } else {
                cntv[a[i].Y] ++;
                cntvv[a[i].X]++;
                vv++;
            }
        } else if(h[a[i].Y]){
            cnth[a[i].X] ++;
            cnthh[a[i].Y] ++;
            hh++;
        }
    }

    ll ans = 0;
    ans += both * (k - 1);
    ans += vv * hh;
    debug(both, vv, hh, ans);
   
    for(int i=0;i<=1e6;i++){
       
        if(i != 0){
            xl[i] = xl[i-1] + cntv[i];
            yl[i] = yl[i-1] + cnth[i];
        } else {
            xl[i] = cntv[i];
            yl[i] = cnth[i];
        }
        
    }
    for(int i=1e6;i>=0;i--){
        if(i != 1e6){
            xr[i] = xr[i+1] + cntv[i];
            yr[i] = yr[i+1] + cnth[i];
        } else {
            xr[i] = cntv[i];
            yr[i] = cnth[i];
        }
        
    }
    for(int i=0;i<=10;i++){
        debug(xl[i], xr[i], yl[i], yr[i], cntv[i], cnth[i]);
    }
    ll preh, prev;
    preh = prev = 0;
    for(int i=0;i<=1e6;i++){
        if(h[i]){
            debug(i, xl[i], xr[i]);
            ans += (xl[i] - prev) * xr[i];
            prev = xl[i];
        }
        if(v[i]){
            debug(i, yl[i], yr[i]);
            ans += (yl[i] - preh) * yr[i];
            preh = yl[i];
        }
    }
    for(int i=0;i<=1e6;i++){
        if(v[i]){
            ans -= cntvv[i] * (cntvv[i] - 1) / 2;
        }
        if(h[i]){
            ans -= cnthh[i] * (cnthh[i] - 1) / 2;
        }
    }
    debug(ans);
    ans = ((k-1) * k / 2) - ans;

    cout << ans << endl;




}


/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}