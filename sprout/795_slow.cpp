#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<double,double> pdd;
#define sqrtl sqrt
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
gp_hash_table<ll, ll> ht;
// gp_hash_table<pll, ll>::iterator it;

ll ans = INF;
ll d;
vector<pll> a;

ll dis(pll i, pll j){
    ll dx = i.X - j.X;
    ll dy = i.Y - j.Y;
    return dx * dx + dy * dy;
}

ll pairtoll(pll z){
    return z.X * MOD + z.Y;
}

bool collide(pll cur, int id){
    bool flag = false;
    for(int i=-2;i<=2;i++){
        for(int j=-2;j<=2;j++){
            if(i == 0 && j == 0) continue;
            auto it = ht.find(pairtoll(mp(cur.X + i, cur.Y + j)));
            if(it != ht.end() && it->second != id){
                ll d_ = dis(a[id], a[it->second]);
                debug(id);
                if(d_ < ans){
                    d = sqrt(d_);
                    ans = d_;
                    flag = true;    
                }
                
                // break;
            }
        }
    }

    return flag;
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    

    int n;
    cin >> n;
    a.resize(n);
    ll minx, miny;
    minx = miny = INF;
    for(int i=0;i<n;i++){
        cin >> a[i].X >> a[i].Y;
        minx = min(minx, a[i].X);
        miny = min(miny, a[i].Y);
    }
    for(int i=0;i<n;i++){
        a[i].X += abs(minx);
        a[i].Y += abs(miny);
    }
    ll ans = dis(a[0], a[1]);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans = min(ans, dis(a[i], a[j]));
        }
    }

    cout << ans << endl;

    return 0;
}