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

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    while(true){
        bool flag = true;
        int n = 6;
        vector<int> a(7);
        for(int i=1;i<=n;i++){
            cin >> a[i];
            if(a[i] != 0) flag = false;
        }
        if(flag) break;

        ll ans = 0;
        ans += a[6];
        a[6] = 0;
        ans += a[3] / 4;
        a[3] %= 4;
        ans += a[5];
        a[1] -= min(a[1], a[5] * 11);
        a[5] = 0;
        debug(a[1]);
        ans += a[4];
        if(a[2] < a[4] * 5) a[1] -= min(a[1], ((a[4] * 5) - a[2]) * 4);
        a[2] -= min(a[2], a[4] * 5);
        a[4] = 0;
        debug(a[2]);
        debug(a[1]);
        debug(ans);
        if(a[3] == 1){
            ans ++;
            if(a[2] < 5){
                a[1] -= min(a[1], 27 - a[2] * 4);
            } else {
                a[1] -= min(a[1], 7);                
            }
            a[2] -= min(a[2], 5);
        } else if(a[3] == 2){
            ans ++;
            if(a[2] < 3){
                a[1] -= min(a[1], 18 - a[2] * 4);
            } else {
                a[1] -= min(a[1], 6);
            }
            a[2] -= min(a[2], 3);
        } else if(a[3] == 3){
            ans ++;
            if(a[2] < 1){
                a[1] -= min(a[1], 9);
            } else {
                a[1] -= min(a[1], 5);
            }
            a[2] -= min(a[2], 1);
        }
        debug(a);
        ans += a[2] / 9;
        a[2] %= 9;
        ans += a[1] / 36;
        a[1] %= 36;
        debug(((double(a[2] * 4) + double(a[1]))/36.0));
        ans += ceil(((double(a[2] * 4) + double(a[1]))/36.0));
        cout << ans << endl;
    }

    return 0;
}
