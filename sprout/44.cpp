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

pii dir[4] = {mp(1, 0), mp(-1, 0), mp(0, 1), mp(0, -1)};
char ma[100][100];
bool vis[100][100];
int n, m;
// int ans = iNF;
queue<pii> q;

// void dfs(pii cur, pii par, int step){
//     // vis[cur.X][cur.Y] = true;
//     if(step >= ans) return;
//     debug(cur, par, step);
//     int i, j;
//     for(int k=0;k<4;k++){
//         i = cur.X + dir[k].X;
//         j = cur.Y + dir[k].Y;
//         if(0 <= i && i < n && 0 <= j && j < m && ma[i][j] != '#' && i != par.X && j != par.Y){
//             if(ma[i][j] == '@'){
//                 ans = min(ans, step+1);
//             } else if(ma[i][j] == '.'){
//                 if(step >= ans) return;
//                 dfs(mp(i, j), cur, step+1);
//             }
//         }
//     } 
// }


int bfs(pii pos){
    int step = 0;
    q.push(pos);
    q.push(mp(-1, -1));

    while(q.size() != 1){
        
        pii cur = q.front();
        debug(cur, step);
        q.pop();
        if(cur.X == -1){
            step++;
            q.push(mp(-1, -1));
            continue;
        }
        vis[cur.X][cur.Y] = true;
        int i, j;
        for(int k=0;k<4;k++){
            i = cur.X + dir[k].X;
            j = cur.Y + dir[k].Y;
            if(0 <= i && i < n && 0 <= j && j < m && ma[i][j] != '#'){
                if(ma[i][j] == '@'){
                    return step + 1;
                } else if(ma[i][j] == '.' && vis[i][j] == false){
                    q.push(mp(i, j));
                }
            }
        }
    }

    return iNF;
}


/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    while(true){
        cin >> n;
        if(n == 0) break;
        string s;
        cin >> s;
        m = s.size();
        pii cat;
        for(int j=0;j<m;j++) ma[0][j] = s[j];
        REP(i, n) REP(j, m) vis[i][j] = false;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0) break;
                cin >> ma[i][j];
                if(ma[i][j] == 'K'){
                    cat.X = i;
                    cat.Y = j;
                } 
            }
        }
        while(!q.empty()) q.pop();
        int ans = bfs(cat);
        // dfs(cat, mp(-1, -1), 0);
        if(ans == iNF){
            cout << "= =\"" << endl;
        } else {
            cout << ans << endl;
        }

    }

    return 0;
}