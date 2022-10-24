// :80 <enter>
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

bool all_c(string s, char c){
    int sz = s.size();
    for(int i=0;i<sz;i++){
        if(s[i] != c) return false;
    }
    return true;
}

bool has_c(string s, char c){
    int sz = s.size();
    for(int i=0;i<sz;i++){
        if(s[i] == c) return true;
    }
    return false;
}

bool check(string s){
    int sz = s.size();
    for(int i=0;i<26;i++){
        int k = 0;
        char c = 'A' + i;
        for(int j=0;j<sz;j++){
            if(k == 0){
                if(s[j] == c){
                    k = 1;
                }
            } else if(k == 1){
                if(s[j] != c){
                    k = 2;
                }
            } else if(k == 2 and s[j] == c){
                return false;
            }
        }
    }

    return true;
}

void solve(){
    int n;
    cin >> n;
    vector<string> a(n);
    for(auto &i: a) cin >> i;
    for(auto &i: a){
        if(check(i) == false){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    for(int i=0;i<26;i++){
        debug(a);
        char c = 'A' + i;
        vector<string> tmp;
        string merged = "";
        for(auto it=a.begin();it!=a.end();){
            if(has_c(*it, c)){
                tmp.push_back(*it);
                it = a.erase(it);
            } else {
                it ++;
            }
        }
        int sz = tmp.size();
        int head = 0;
        int tail = 0;
        int middle = 0;
        int head_idx, tail_idx;
        head_idx = tail_idx = -1;
        if(sz == 1){
            a.push_back(tmp[0]);
        } else if(sz > 1){
            for(int j=0;j<sz;j++){
                if(all_c(tmp[j], c)){
                    middle ++;
                } else if(*(tmp[j].begin()) == c){
                    tail ++;
                    tail_idx = j;
                } else if(*(tmp[j].rbegin()) == c){
                    head ++;
                    head_idx = j;
                }
            }
            debug(c, tail, head, middle);
            if(tail + head + middle != sz || head >= 2 || tail >= 2){
                cout << "IMPOSSIBLE" << endl;
                return;
            } else {
                if(head_idx != -1){
                    merged += tmp[head_idx];
                }
                for(int j=0;j<sz;j++){
                    if(j != head_idx and j != tail_idx){
                        merged += tmp[j];
                    }
                }
                if(tail_idx != -1){
                    merged += tmp[tail_idx];
                }
            }
            a.push_back(merged);
        }
    }
    string ans = "";
    for(auto i: a){
        ans += i;
    }
    if(check(ans)){
        cout << ans;
    } else {
        cout << "IMPOSSIBLE";
    }
    cout << endl;
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t = 1;
    cin >> t;
    for(int i=0;i<t;i++){
        cout << "CASE #" << i+1 << ": ";
        solve();
    }

    return 0;
}
