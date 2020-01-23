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
// #define mp make_pair
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
const ll MAXN = 105;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
    int min_val, min_cnt, lazy_tag;
}tr[MAXN * 4];

pii seat[MAXN];
vector<vector<int>> mp;
int tags[MAXN], type, HW;
int dx[4] = {0, -1, 0, -1}, dy[4] = {0, 0, -1, -1};

void merge(node &u, node lch, node rch){
    if (lch.min_val > rch.min_val) swap(rch, lch);

    u.min_val = lch.min_val;
    u.min_cnt = lch.min_cnt;
    if(lch.min_val == rch.min_cnt)
        u.min_cnt += rch.min_cnt;
}

void push_down(node &u, node &lch, node &rch) {
    lch.min_val += u.lazy_tag;
    lch.lazy_tag += u.lazy_tag;
    rch.min_val += u.lazy_tag;
    rch.lazy_tag += u.lazy_tag;
    u.lazy_tag = 0;
}

void build(int idx, int lb, int rb){
    if(lb == rb){
        tr[idx].min_val = tags[lb];
        tr[idx].min_cnt = 1;
        tr[idx].lazy_tag = 0;
        return;
    }
    int mid =(lb + rb) >> 1;
    build(idx * 2, lb, mid);
    build(idx * 2 + 1, mid + 1, rb);
    merge(tr[idx], tr[idx * 2], tr[idx * 2 + 1]);
}

void modify(int idx, int lb, int rb, int ql ,int qr, int val){
    if (ql <= rb && rb <= qr) {
        tr[idx].min_val += val;
        tr[idx].lazy_tag += val;
        return;
    }
    push_down(tr[idx], tr[idx * 2], tr[idx * 2 + 1]);
    int mid = (lb + rb) >> 1;
    if(ql <= mid){
        modify(idx * 2, lb, mid, ql, qr, val);
    }
    if(qr > mid){
        modify(idx * 2 + 1, mid + 1, rb, ql, qr, val);
    }
    merge(tr[idx], tr[idx * 2], tr[idx * 2 + 1]);
}

void add_segemnt(int lb, int rb, int val){
    if (lb == rb ) return;
    if(type == 0){
        tags[lb] += val;
        tags[rb] -= val;

    } else {
        modify(1, 1, HW, lb, rb - 1, val);
    }
}

void pattern(int x, int y, int val){
    int a[4] = {mp[x][y], mp[x+1][y], mp[x][y+1], mp[x+1][y+1]};
    sort(a, a+4);
    add_segemnt(a[0], a[1], val);
    add_segemnt(a[2], a[3], val);
}

void give_init_chart(int H, int W, vector<int> R, vector<int> C){
    HW = H * W;
    mp.resize(H+2, vector<int>(W + 2, HW + 1));
    for(int i=0;i<HW;i++){
        mp[R[i] + 1][C[i] + 1] = i + 1;
        seat[i+1] = make_pair(R[i] + 1, C[i] + 1);
    }
    for(int i=0;i<=W;i++)
        for(int j=0;j<=H;j++)
            pattern(i, j, 1);
    for(int i=1;i<=HW;i++){
        tags[i] += tags[i-1];
    }
    build(1, 1, HW);
    type = 1;
}   

int sovle(){
    return tr[1].min_cnt;
}

int swap_seats(int a, int b){
    ++a, ++b;

    REP(i, 4) pattern(seat[a].first + dx[i], seat[a].second + dy[i], -1);
    mp[seat[a].first][seat[a].second] = b;
    REP(i, 4) pattern(seat[a].first + dx[i], seat[a].second + dy[i], 1);

    REP(i, 4) pattern(seat[b].first + dx[i], seat[b].second + dy[i], -1);
    mp[seat[b].first][seat[b].second] = a;
    REP(i, 4) pattern(seat[b].first + dx[i], seat[b].second + dy[i], 1);

    swap(seat[a], seat[b]);
    return tr[1].min_cnt;

}

int main(){
    int h, w, tmp;
    cin >> h >> w;
    HW = h * w;
    vector<int> R(HW);
    vector<int> C(HW);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> tmp;
            tmp --;
            R[tmp] = i;
            C[tmp] = j;
        }
    }
    give_init_chart(h, w, R, C);
    cout <<  tr[1].min_cnt << endl;
}