// djisktra with priority queue and memory optimize

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


int n, m;
vector<vector<pll>> w;
vector<ll> d;
vector<int> parent;
void dijkstra(int src){
    vector<bool> visit(n+1, false);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for(int i=1;i<n;i++){
        pq.push(mp(INF, i));
    }
    d[src] = 0;
    parent[src] = src;
    while(!pq.empty()){
        pll u = pq.top();
        pq.pop();
        for(auto i:w[u.second]){
            ll alt = d[u.second] + i.second;
            if(alt < d[i.first]){
                d[i.first] = alt;
                parent[i.first] = u.second;
                pq.push(mp(alt, i.first));
            }
        }
    }
    // for(int k=1;k<=n;k++){
    //     debug(d, parent, visit);
    //     int a = -1, min = INF;
    //     for(int i=1;i<=n;i++){
    //         if(!visit[i] && d[i] < min){
    //             a = i;
    //             min = d[i];
    //         }
    //     }
    //     if(a == -1) break;
    //     visit[a] = true;
    //     for(auto i:w[a]){
    //         if(!visit[i.first] && d[a] + i.second < d[i.first]){
    //             d[i.first] = d[a] + i.second;
    //             parent[i.first] = a;
    //         }
    //     }
    // }
}


/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    cin >> n >> m;
    w.resize(n+1);
    d.resize(n+1, INF);
    parent.resize(n+1, -1);
    ll a, b, tmp;
    for(int i=0;i<m;i++){
        cin >> a >> b >> tmp;
        w[a].pb(mp(b, tmp));
        w[b].pb(mp(a, tmp));
    }
    dijkstra(1);
    vector<int> ans;
    int cur;
    if(d[n] != INF){
        cur = n;
        while(cur != 1){
            ans.push_back(cur);
            cur = parent[cur];
        }
        ans.push_back(1);
        int sz = ans.size();
        for(int i=sz-1;i>=0;i--){
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    

    return 0;
}