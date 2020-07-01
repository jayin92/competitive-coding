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
const ll MAXN = 10000;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


vector<vector<vector<bool>>> a;
vector<vector<bool>> visit;
// bool a[MAXN][MAXN][4];
// bool visit[MAXN][MAXN];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m;

bool check(pii s, int i){
    debug(s.X, s.Y, i);
    debug(a[s.X][s.Y][i]);
    if(a[s.X][s.Y][i] == 1){
        return false;
    }

    int x = s.X + dx[i];
    int y = s.Y + dy[i];
    if(x < 0 || x >= n || y < 0 || y >= m) return false;

    return true;
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                cout << a[i][j][k] << " (" << i << ", " << j << ") ";
            }
            cout << " ";
        }
        cout << endl;
    }
}

int bfs(pii s, pii e){
    queue<pii> q;

    q.push(s);
    q.push(mp(-1, -1));
    int ans = 0;
    while(!q.empty()){
        pii cur = q.front();
        debug(cur);
        q.pop();
        if(cur == e){
            return ans;
        }
        if(cur.X == -1){
            ans ++;
            if(q.empty()) break;
            q.push(mp(-1, -1));
            continue;
        }
        visit[cur.X][cur.Y] = 1;

        for(int i=0;i<4;i++){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];
            if(check(cur, i) && visit[x][y] == false){
                q.push(mp(x, y));
            }
        }
    }

    return -1;
    
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    cin >> n >> m;
    a.resize(n, vector<vector<bool>>(m, vector<bool>(4, false)));
    visit.resize(n, vector<bool>(m, false));
    char c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){   
                cin >> c;
                if(c == ' '){
                    k --;
                    debug("test");
                    continue;
                }
                a[i][j][k] = c - '0';
            }
        }
    }
    // print();
    // cout << a[0][1][0] << endl;
    pii s, e;
    cin >> s.X >> s.Y >> e.X >> e.Y;
    s.X --;
    s.Y --;
    e.X --;
    e.Y --;

    cout << bfs(s, e) << endl;




    return 0;
}