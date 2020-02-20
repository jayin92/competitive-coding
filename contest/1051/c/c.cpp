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

bool cmp(const pii &a, const pii &b){
    return (a.second < b.second);
}
vector<int> s;
map<int, int> m;
vector<char> ans;
int n;

void ins(int x, char c){
    debug(x, c);
    for(int i=0;i<n;i++){
        if(s[i] == x && (ans[i] != 'A' && ans[i] != 'B')){
            ans[i] = c;
            debug(i);
            break;
        }
    }
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    cin >> n;
    s.resize(n);
    ans.resize(n);
    REP(i, n){
        cin >> s[i];
        m[s[i]] ++;
    }
    debug(m);
    vector<pii> v;
    for(auto it=m.begin();it!=m.end();it++){
        v.eb(it -> first, it -> second);
    }
    sort(ALL(v), cmp);
    debug(v);
    debug(ans);
    int na, nb;
    na = nb = 0;
    for(auto i:v){
        if(i.second == 1){
            if(na > nb){
                nb ++;
                ins(i.first, 'B');
            } else if(na == nb){
                na ++;
                ins(i.first, 'A');
            } else {
                na++;
                ins(i.first, 'A');
            }
        } else if(i.second == 2){
            na++;nb++;
            ins(i.first, 'A');
            ins(i.first, 'B');
        } else {
            if(na > nb){
                nb++;
                ins(i.first, 'B');
                REP(j, i.second - 1){
                    ins(i.first, 'A');
                }
            } else if (na == nb){
                REP(j, i.second){
                    ins(i.first, 'A');
                }
            } else {
                na ++;
                ins(i.first, 'A');
                REP(j, i.second - 1){
                    ins(i.first, 'B');   
                }
            }
        }
    }
    
    if(na != nb){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for(auto i:ans){
            cout << i;
        }
        cout << endl;

    }
    debug(ans);

    return 0;
}