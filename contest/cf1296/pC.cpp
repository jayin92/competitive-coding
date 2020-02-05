#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
#define debug(...)
#define pary(...)
#define endl '\n'
#endif

const ll MOD = 1000000007;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int iNF = 0x3f3f3f3f;
const ll MAXN = 200005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/********** Good Luck :) **********/

int main () {
    pii dir[4] = {mp(-1, 0), mp(1, 0), mp(0, 1), mp(0, -1)};
    TIME(main);
    IOS();
    int t;
    cin >> t;
    int n;
    int x[MAXN], y[MAXN];
    bool flag;
    int l, r;
    char tmp;
    while(t--){
        cin >> n;
        if(n == 0){
            continue;
        }
        cin >> tmp;
        if(tmp == 'L'){
            x[0] = dir[0].X;
            y[0] = dir[0].Y;
        } else if (tmp == 'R'){
            x[0] = dir[1].X;
            y[0] = dir[1].Y;
        } else if (tmp == 'U'){
            x[0] = dir[2].X;
            y[0] = dir[2].Y;
        } else if (tmp == 'D'){
            x[0] = dir[3].X;
            y[0] = dir[3].Y;
        }        
        debug("t1");

        for(int i=1;i<n;i++){
            cin >> tmp;
            debug(i);
            if(tmp == 'L'){
                x[i] = x[i - 1] + dir[0].X;
                y[i] = y[i - 1] + dir[0].Y;
            } else if (tmp == 'R'){
                x[i] = x[i - 1] + dir[1].X;
                y[i] = y[i - 1] + dir[1].Y;
            } else if (tmp == 'U'){
                x[i] = x[i - 1] + dir[2].X;
                y[i] = y[i - 1] + dir[2].Y;
            } else if (tmp == 'D'){
                x[i] = x[i - 1] + dir[3].X;
                y[i] = y[i - 1] + dir[3].Y;
            }
        }

        l = r = 0;
        flag = false;
        for(int i=1;i<4;i+=2){
            for(l=0,r=i;l<n && l + i < n;l++,r++){
                if(x[r] - (l == 0 ? 0 : x[l - 1]) == 0 && y[r] - (l == 0 ? 0 : y[l - 1]) == 0){
                    cout << l + 1 << " " << r + 1 << endl;
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        debug("t1");
        for(int i=7;i<n;i+=4){
            for(l=0,r=i;l<n && l + i < n;l++,r++){
                if(x[r] - (l == 0 ? 0 : x[l - 1]) == 0 && y[r] - (l == 0 ? 0 : y[l - 1]) == 0){
                    cout << l + 1 << " " << r + 1 << endl;
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }

        if(flag == false){
            cout << -1 << endl;
        }
    }
    return 0;
}