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



char ma[1000][1000];
int n;
int ans = -1;
char x;
queue<pii> q;

pii dir[8] = {mp(1, 0), mp(-1, 0), mp(0, 1), mp(0, -1), mp(1, 1), mp(1, -1), mp(-1, 1), mp(-1, -1)};

// TODO:parent

char mix(char a, char b){
    if(a == 'E') return b;
    if(a == 'R' && b == 'Y') return 'O';
    if(a == 'R' && b == 'B') return 'P';
    if(a == 'Y' && b == 'B') return 'G';
    if(a == 'O' || a == 'P' || a == 'G' || a == 'D') return 'D';

    swap(a, b);

    if(a == 'E') return b;
    if(a == 'R' && b == 'Y') return 'O';
    if(a == 'R' && b == 'B') return 'P';
    if(a == 'Y' && b == 'B') return 'G';
    if(a == 'O' || a == 'P' || a == 'G' || a == 'D') return 'D';    

    return 'E';
}

int count(){
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ma[i][j] == x) res ++;
        }
    }
    return res;
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ma[i][j] == 'E') cout << "  "; 
            else cout << ma[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(){
    while(q.size() != 1){
        pii pos = q.front();
        char col = ma[pos.X][pos.Y];
        // debug(pos);
        q.pop();
        if(pos.X == -1){
            q.push(mp(-1, -1));
            ans = max(ans, count());
            cout << endl;
            print();
            continue;
        }
        for(int k=0;k<8;k++){
            int i, j;
            i = pos.X + dir[k].X;
            j = pos.Y + dir[k].Y;
            // debug(i, j);
            if(0 <= i && i < n && 0 <= j && j < n && ma[i][j] != 'D'){
                ma[i][j] = mix(col, ma[i][j]);
                q.push(mp(i, j));
            }
        }
        
    }

}


/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        REP(i, n){
            REP(j, n){
                ma[i][j] = 'E';
            }
        }
        for(int i=0;i<3;i++){
            char c;
            int a, b;
            cin >> c >> a >> b;
            ma[a][b] = c;
            q.push(mp(a, b));
        }
        cin >> x;
        q.push(mp(-1, -1));
        bfs();
        cout << ans << endl;


        
    }

    return 0;
}