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
#ifdef tmd
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

struct Node{
    int val, tag;
    Node *lc, *rc;
    Node(){
        tag = val = 0;
        lc = rc = nullptr;
    }
    void pull(){
        val = lc -> val + rc -> val;
    }
};

const int n = 5;
int v[n+1] = {0, 1, 16, 2, 8, 4}; // input, 1-base

Node* build(int L, int R){
    Node *node = new Node();
    if( L == R ){
        node -> val = v[L];
        return node;
    }
    int mid = (L + R) >> 1;
    node -> lc = build(L, mid);
    node -> rc = build(mid+1, R);
    node -> pull();
    return node;
}

void push(Node* node, int L, int R){
    if(!node -> tag) return;
    if(L != R){
        int mid = ( L + R ) >> 1;
        node -> lc -> tag += node -> tag;
        node -> rc -> tag += node -> tag;
        node -> lc -> val += node -> tag * (mid - L + 1); 
        node -> rc -> val += node -> tag * ( R - mid ); 
    }
    node -> tag = 0;
}

void modify(Node* node, int L, int R, int ql, int qr, int d){
    debug(L, R);
    if(ql > R || qr < L) return;
    if(ql <= L && R <= qr){
        node -> tag += d;
        node -> val += d * (R - L + 1);
        return;
    }
    push(node, L, R);
    int mid = (L + R) >> 1;
    modify(node -> lc, L, mid, ql, qr, d);
    modify(node -> rc, mid+1, R, ql, qr, d);
    node -> pull();
}

int query(Node* node, int L, int R, int ql, int qr){
    if(ql > R || qr < L) return 0;
    if(ql <= L && R <= qr) return node -> val;
    push(node, L, R);
    int mid = (L + R) >> 1;
    return query(node -> lc, L, mid, ql, qr) + query(node -> rc, mid + 1, R, ql, qr);
}
/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    Node* root = build(1, n);
    // cout << query(root, 1, n, 1, 5) << endl;
    modify(root, 1, n, 1, 4, 3);

    // cout << query(root, 1, n, 3, 3) << endl;

    return 0;
}