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

struct ans_{
  int x, y, d;  
};

struct para{
    pii x;
    vector<pii> block;
    int r;
};

bool cmp(ans_ aa, ans_ bb){
    if(aa.x != bb.x) return aa.x < bb.x;
    if(aa.y != bb.y) return aa.y < bb.y;
    if(aa.d != bb.d) return aa.d < bb.d;

    return false;
}


vector<vector<bool>> a;
vector<vector<bool>> vis[4];

pii xx;
vector<pii> blockx;
vector<ans_> ans;


int n, m;

bool check_point(pii x){
    if(x.X < 0 || x.X >= n || x.Y < 0 || x.Y >= m) return false;
    if(a[x.X][x.Y] == false) return false;

    return true;
}

bool check(pii x, vector<pii> block){
    int sz = block.size();
    if(check_point(x) == false) return false;
    for(int i=0;i<sz;i++){
        if(check_point({x.X + block[i].X, x.Y + block[i].Y}) == false) return false;
    }

    return true;
}

pair<pii, vector<pii>> move_x(pii x, vector<pii> block, int r){
    x.Y += r;
    if(check(x, block) == false){
        return {{-1, -1}, {}};
    }

    return {x, block};
    
}

pair<pii, vector<pii>> down(pii x, vector<pii> block){
    x.X += 1;
    if(check(x, block) == false){
        return {{-1, -1}, {}};
    }

    return {x, block};
}


pair<pii, vector<pii>> rotate(pii x, vector<pii> block, int r){
    int sz = block.size();
    vector<pii> tmp(block);
    debug(x, r);
    bool flag = true;
    for(int k=0;k<r;k++){
        for(int i=0;i<sz;i++){
            tmp[i] = {-tmp[i].second, tmp[i].first};
        }
        if(check(x, tmp) == false){
            flag = false;
            break;
        }
    }
    if(flag){
        return {x, tmp};
    }
    tmp = block;
    debug(x, r);
    for(int k=0;k<4-r;k++){
        for(int i=0;i<sz;i++){
            debug(tmp[i]);
            tmp[i] = {tmp[i].second, -tmp[i].first};
            debug(tmp[i]);
        }
        if(check(x, tmp) == false){
            return {{-1, -1}, {}};
        }
    }

    if(check(x, tmp) == true){
        return {x, tmp};
    } else {
        return {{-1, -1}, {}};        
    }

    
}


void solve(pii xxx, vector<pii> blockxx, int rxx){
    queue<para> q;
    q.push({xxx, blockxx, rxx});
    while(!q.empty()){
        auto x = q.front().x;
        auto block = q.front().block;
        auto r = q.front().r;
        debug(x, r);
        q.pop();

        if(vis[r][x.X][x.Y] == true){
            continue;
        } else {
            vis[r][x.X][x.Y] = true;
        }

        auto resd = down(x, block);
        if(resd.X.X == -1){
            ans.push_back({x.X, x.Y, r});
        }

        for(int i=4-r, cnt = 0;cnt<4;cnt++, i++){
            debug(r + i, cnt, i);
            auto res = rotate(x, block, i % 4);
            if(res.X.X != -1){
                q.push({res.X, res.Y, (r + i) % 4});
            }
        }

        auto res = move_x(x, block, -1);
        if(res.X.X != -1)
            q.push({res.X, res.Y, r});

        res = move_x(x, block, 1);
        if(res.X.X != -1)
            q.push({res.X, res.Y, r});
        
        if(resd.X.X != -1){
            q.push({resd.X, resd.Y, r});

        }
    }
    

}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    cin >> n >> m;
    a.resize(n, vector<bool>(m));
    vis[0].resize(n, vector<bool>(m, false));
    vis[1].resize(n, vector<bool>(m, false));
    vis[2].resize(n, vector<bool>(m, false));
    vis[3].resize(n, vector<bool>(m, false));
    for(int i=0;i<n;i++){
        string t;
        cin >> t;
        for(int j=0;j<m;j++){
            if(t[j] == 'X'){
                xx = {i, j};
                a[i][j] = true;
            } else if(t[j] == 'x'){
                blockx.push_back({i, j});
                a[i][j] = true;
            } else if(t[j] == 'o'){
                a[i][j] = false;
            } else if(t[j] == '.'){
                a[i][j] = true;
            }
        }
    }
    int sz = blockx.size();
    for(int i=0;i<sz;i++){
        blockx[i] = {blockx[i].X - xx.X , blockx[i].Y - xx.Y};
    }
    solve(xx, blockx, 0);
    debug(ans.size());
    sz = ans.size();
    // sort(ALL(ans), cmp);
    for(int i=0;i<sz;i++){
        cout << ans[i].x << " " << ans[i].y << " " << ans[i].d << endl;
    }
    return 0;
}