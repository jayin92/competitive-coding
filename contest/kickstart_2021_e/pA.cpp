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

bool cmp(pii a, pii b){
    return a.Y > b.Y;
}

bool check(string s, vector<char> ans){
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] == ans[i]) return false;
    }

    return true;
}

void solve(int t){
    string s;
    cin >> s;
    cout << "Case #" << t + 1 << ": ";
    int n = s.size();
    vector<char> ans(n);
    vector<int> cnt(26, 0);
    vector<vector<int>> idx(26);
    vector<pii> cnt_(26);
    for(int i=0;i<26;i++) cnt_[i] = {i, 0};
    int tmp = 0;
    for(auto i: s){
        cnt[i - 'a'] ++;
        cnt_[i - 'a'].Y ++;
        idx[i - 'a'].pb(tmp++);
    }
    for(int i=0;i<26;i++){
        if(n - cnt[i] < cnt[i]){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    sort(ALL(cnt_), cmp);
    debug(cnt_);
    for(int i=0;i<26;i++){
        if(cnt_[i].Y == 0) break;
        for(auto k: idx[cnt_[i].X]){
            debug(ans, k);
            for(int j=25;j>=0;j--){
                if(cnt[cnt_[j].X] > 0 and cnt_[j].X != cnt_[i].X){
                    ans[k] = (char)(cnt_[j].X + 'a');
                    cnt[cnt_[j].X] --;
                    break;
                }
            }
        }
    }

    assert(check(s, ans));    

    for(auto i: ans) cout << i;
    cout << endl;
}



/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t;
    cin >> t;
    REP(i, t){
        solve(i);
    }

    return 0;
}