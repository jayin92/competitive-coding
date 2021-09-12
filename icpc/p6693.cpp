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


struct V{
    int a1, a2, y0;
};


struct H{
    int x0, b1, b2;
};

bool inter(V v, H h){
    int a1 = v.a1;
    int a2 = v.a2;
    int y0 = v.y0;
    int b1 = h.b1;
    int b2 = h.b2;
    int x0 = h.x0;
    return (b1 <= y0 and y0 <= b2) and (a1 <= x0 and x0 <= a2);
}
void solve(){
    int n;
    cin >> n;
    vector<pii> a(2);
    vector<pii> b(2);
    int idx1, idx2;
    idx1 = idx2 = 0;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            if(s[j] == '1'){
                a[idx1++] = {i, j};
            } else if(s[j] == '2'){
                b[idx2++] = {i, j};
            }
        }
    }
    V va1, va2, vb1, vb2;
    va1.a1 = a[0].X;
    va1.a2 = a[1].X;
    va1.y0 = a[0].Y;

    va2.a1 = a[0].X;
    va2.a2 = a[1].X;
    va2.y0 = a[1].Y;

    vb1.a1 = b[0].X;
    vb1.a2 = b[1].X;
    vb1.y0 = b[0].Y;

    vb2.a1 = b[0].X;
    vb2.a2 = b[1].X;
    vb2.y0 = b[1].Y;
    
    H ha1, ha2, hb1, hb2;
    ha1.b1 = min(a[0].Y, a[1].Y);
    ha1.b2 = max(a[0].Y, a[1].Y);
    ha1.x0 = a[0].X;

    ha2.b1 = min(a[0].Y, a[1].Y);
    ha2.b2 = max(a[0].Y, a[1].Y);
    ha2.x0 = a[1].X;

    hb1.b1 = min(b[0].Y, b[1].Y);
    hb1.b2 = max(b[0].Y, b[1].Y);
    hb1.x0 = b[0].X;

    hb2.b1 = min(b[0].Y, b[1].Y);
    hb2.b2 = max(b[0].Y, b[1].Y);
    hb2.x0 = b[1].X;

    bool flag = true;
    flag |= inter(va1, hb1);
    flag |= inter(va1, hb2);
    flag |= inter(va2, hb1);
    flag |= inter(va2, hb2);
    flag |= inter(vb1, ha1);
    flag |= inter(vb1, ha2);
    flag |= inter(vb2, ha1);
    flag |= inter(vb2, ha2);

    if(flag){
        cout << a[1].X - a[0].X + abs(a[1].Y - a[0].Y) + b[1].X - b[0].X + abs(b[1].Y - b[0].Y) + 2 << endl;
    } else {
        cout << -1 << endl;
    }
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