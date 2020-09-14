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

int n;
struct Node{
    Node* parent = nullptr;
    vector<Node*> child;

    int id;
    int dep = 0;
    int child_dep = 0;
};

int dep_;
void dfs(Node* src, int dep){
    // int sz = src -> child.size();
    src -> dep = dep;
    for(auto i:src -> child){
        dfs(i, dep+1);
    }
    if(src -> child.size() == 0){
        Node* cur = src;
        src -> child_dep = dep;
        while(cur -> parent != nullptr){
            cur = cur -> parent;
            cur -> child_dep = max(cur -> child_dep, dep);
        }
    }

    // return dep;
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    cin >> n;
    vector<Node*> t;
    Node* tmp_ = new Node;
    t.pb(tmp_);
    for(int i=1;i<=n;i++){
        Node* tmp = new Node;
        tmp -> parent = nullptr;
        tmp -> child.clear();  
        tmp -> id = i;

        t.pb(tmp);
    }
    debug(t);
    for(int i=1;i<=n;i++){
        int m;
        cin >> m;
        for(int j=0;j<m;j++){
            int a;
            cin >> a;
            t[a] -> parent = t[i];
            t[i] -> child.push_back(t[a]);
        }
    }

    Node* cur = t[1];
    while(cur -> parent != nullptr){
        cur = cur -> parent;
    }

    cout << cur -> id << endl;
    
    dfs(cur, 0);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans += t[i] -> child_dep - t[i] -> dep;
    }

    cout << ans << endl;

    
    

    

    return 0;
}