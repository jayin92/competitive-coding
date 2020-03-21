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

vector<pii> em;
int sz;
bool flag = true;

struct Node{
    Node* parent;
    vector<Node*> child;
    vector<bool> visit;

    pii pos;
    int val;
    int depth;
};


void print(vector<vector<int>> b){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << b[i][j];
        }
    }
    cout << endl;
}

bool check(pii pos, int val, vector<vector<int>> b){
    for(int i=0;i<9;i++){
        if(b[pos.X][i] == val || b[i][pos.Y] == val){
            return false;
        }
    }

    for(int i=(pos.X/3)*3;i<(pos.X/3)*3+3;i++){
        for(int j=(pos.Y/3)*3;j<(pos.Y/3)*3+3;j++){
            if(b[i][j] == val){
                return false;
            }
        }
    }

    return true;
}

void build(Node* cur, vector<vector<int>> b){
    if(flag == false) return;
    debug(cur -> depth);
    if(cur -> depth == sz){
        print(b);
        flag = false;
        return;
    }
    for(auto z:em){
        if(cur -> visit[z.X * 9 + z.Y] == false){
            for(int i=1;i<=9;i++){ 
                if(check(z, i, b)){
                    vector<vector<int>> b_tmp(b);
                    b_tmp[z.X][z.Y] = i;
                    Node* tmp = new Node;
                    tmp -> parent = cur;
                    tmp -> visit = cur -> visit;
                    tmp -> visit[cur -> pos.X * 9 + cur -> pos.Y] = true;
                    // tmp -> visit[z.X * 9 + z.Y] = true;
                    tmp -> pos = z;
                    tmp -> depth = cur -> depth + 1;
                    tmp -> val = i;
                    cur -> child.pb(tmp);
                    build(tmp, b_tmp);
                }
            }
        }
    }
}

/********** Good Luck :) **********/
int main () {
    IOS();
    TIME(main);
    Node* root = new Node;
    vector<vector<int>> b(9, vector<int>(9));
    string s;
    root -> visit.resize(81, true);
    while(true){
        cin >> s;
        if(s == "end") break;        
        root -> val = 0;
        root -> parent = nullptr;
        root -> child.clear();
        root -> depth = 0;
        flag = true;
        em.clear();
        fill(ALL(root->visit), true);
        debug(s);
        for(int i=0;i<81;i++){
            if(s[i] == '.'){
                b[i/9][i%9] = 0;
                em.eb(i/9, i%9);
                root -> visit[i] = false;
            } else {
                b[i/9][i%9] = s[i] - '0';
            }
        }
        sz = em.size();
        build(root, b);
        if(flag){
            cout << "No solution." << endl;
        }
        
    }
    return 0;
}