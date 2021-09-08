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

const ll MOD = 998244353;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int iNF = 0x3f3f3f3f;
const ll MAXN = 5005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<vector<ll>>> dp(MAXN, vector<vector<ll>>(MAXN, vector<ll>(2, 0)));
vector<pii> a;
vector<int> b;

ll subset(int n, int sum, int occur, int ori){
    if(sum == 0) return 1;
    if(n == 0) return 0;
    if(dp[sum][ori][occur] != 0) return dp[sum][ori][occur];
    
    if(b[n-1] > sum){
        return dp[sum][ori][occur] = (subset(n-1, sum, occur, ori) % MOD);
    }
    if(b[n-1] == ori and occur == 0){
        return dp[sum][ori][occur] = subset(n-1, sum, occur+1, ori) % MOD;        
    } 
    return dp[sum][ori][occur] = (subset(n-1, sum, occur, ori) + subset(n-1, sum-b[n-1], occur, ori)) % MOD;
}


ll power(ll x, ll y, ll p) 
{ 
	ll res = 1; // Initialize result 

	// Update x if it is more than or 
	// equal to p 
	x = x % p; 

	while (y > 0) { 
		// If y is odd, multiply x with the result 
		if (y & 1) 
			res = (res * x) % p; 

		// y must be even now 
		y = y >> 1; // y = y/2 
		x = (x * x) % p; 
	} 
	return res; 
} 

void solve(){
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    REP(i, n){
        cin >> a[i].X;
        a[i].Y = i;
    }
    REP(i, n){
        cin >> b[i];
    }
    sort(ALL(a), greater<pii>());
    ll ans = 0;
    
    for(int i=0;i<n;i++){
        int ori = a[i].X;
        for(int j=1;j<=max(0, ori-b[a[i].Y]);j++){            
            ans += (subset(n, j, 0, ori)) % MOD;
            ans %= MOD;
            // debug(ans, j);
        }
    }
    cout << ans % MOD << endl;
    
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t;
    // cin >> t;
    t = 1;
    while(t--){
        solve();
    }

    return 0;
}