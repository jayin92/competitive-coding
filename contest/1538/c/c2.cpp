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
    int t;
    cin >> t;
    while(t--){
        int n;
        ll l, r;
        cin >> n >> l >> r;        
        map<ll, ll> a;
        map<ll, int> idx;
        ll tmp;
        for(int i=0;i<n;i++){
            cin >> tmp;
            a[tmp] ++;
        }
        ll ans = 0;
        int sz = a.size();
        vector<ll> dp(sz+1, 0);
        int j = 1;
        for(auto i:a){
            idx[i.X] = j;
            dp[j] = dp[j-1] + i.Y;
            j++;
        }
        set<int> s;
        for(auto i:a){
            ll L = l - i.X;
            ll R = r - i.X;
            if(a.lower_bound(L) == a.end()) continue;
            debug(i.X, a.lower_bound(L) -> X, a.lower_bound(R) -> X);
            ll LL = a.lower_bound(L) -> X;
            ll RR = a.lower_bound(R) -> X;
            if(RR + i.X > R) continue;
            auto idx_l = max(idx[i.X], idx[LL]);
            LL = max(i.X, LL);
            if(a.lower_bound(R) == a.end()){
                RR = a.rbegin() -> X;
            }
            int idx_r = idx[RR];
            if(idx_l > idx_r) continue;
            debug(idx_l, idx_r);
            ll cnt = dp[idx_r] - dp[idx_l-1];
            debug(LL, RR, cnt);
            if(LL == i.X){
                cnt -= i.Y;
                if(s.find(i.X) == s.end()){
                    ans += (i.Y - 1) * i.Y / 2;
                    s.insert(i.X);
                }
            }
            ans += i.Y * cnt;
        }
        cout << ans << endl;
    }

    return 0;
}