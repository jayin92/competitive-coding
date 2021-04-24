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



bool aa[105][105];
int kk;

string solve(int i, int j, bool a, bool b, bool c, bool d){
    /* a b 
       c d */
    int cnt = a + b + c + d;
    if(cnt == 0){
        return "";

    }
    kk++;
    if(cnt == 1){
        stringstream ss;
        if(a){
            ss << i << " " << j << " " << i + 1 << " " << j << " " << i << " " << j + 1 << '\n';
            ss << solve(i, j, !a, !b, !c, d);
            return ss.str();
        } else if(b){
            ss << i << " " << j << " " << i + 1 << " " << j + 1 << " " << i << " " << j + 1 << '\n';
            ss << solve(i, j, !a, !b, c, !d);
            return ss.str();
        } else if(c){
            ss << i << " " << j << " " << i + 1 << " " << j << " " << i + 1 << " " << j + 1 << '\n';
            ss << solve(i, j, !a, b, !c, !d);
            return ss.str();
        } else if(d){
            ss << i + 1 << " " << j + 1<< " " << i + 1 << " " << j << " " << i << " " << j + 1 << '\n';
            ss << solve(i, j, a, !b, !c, !d);
            return ss.str();
        }
        
    } else if(cnt == 2){
        if(a && b){
            stringstream ss;
            ss << i << " " << j << " " << i + 1 << " " << j << " " << i + 1 << " " << j + 1 << '\n';
            ss << solve(i, j, !a, b, !c, !d);
            return ss.str();
        } else if(a && c){
            stringstream ss;
            ss << i << " " << j << " " << i << " " << j + 1 << " "  << i + 1 << " " << j + 1 << '\n';
            ss << solve(i, j, !a, !b, c, !d);
            return ss.str();
        } else if(b && d){
            stringstream ss;
            ss << i << " " << j << " " << i + 1 << " " << j << " " << i + 1 << " " << j + 1 << '\n';
            ss << solve(i, j, !a, b, !c, !d);
            return ss.str();
        } else if(c && d){
            stringstream ss;
            ss << i << " " << j << " " << i << " " << j + 1 << " "  << i + 1 << " " << j + 1 << '\n';
            ss << solve(i, j, !a, !b, c, !d);
            return ss.str();
        } else if(a && d){
            stringstream ss;
            ss << i << " " << j << " " << i + 1 << " " << j << " " << i << " " << j + 1 << '\n';
            ss << solve(i, j, !a, !b, !c, d);
            return ss.str();
        } else if(b && c){
            stringstream ss;
            ss << i << " " << j << " " << i + 1 << " " << j + 1 << " " << i << " " << j + 1 << '\n';
            ss << solve(i, j, !a, !b, c, !d);
            return ss.str();
        }
    } else if(cnt == 3){
        if(a == 0){
            stringstream ss;
            ss << i + 1 << " " << j << " " << i + 1 << " " << j + 1 << " " << i << " " << j + 1 << '\n';
            return ss.str();
        } else if(b == 0){
            stringstream ss;
            ss << i << " " << j << " " << i + 1 << " " << j + 1 << " " << i + 1 << " " << j << '\n';
            return ss.str();
        } else if(c == 0){
            stringstream ss;
            ss << i << " " << j << " " << i << " " << j + 1 << " " << i + 1 << " " << j + 1 << '\n';
            return ss.str();
        } else if(d == 0){
            stringstream ss;
            ss << i << " " << j << " " << i + 1 << " " << j << " " << i << " " << j + 1 << '\n';
            return ss.str();
        }
    } else if(cnt == 4){
        stringstream ss;
        ss << i << " " << j << " " << i + 1 << " " << j << " " << i << " " << j + 1 << '\n';
        ss << solve(i, j, !a, !b, !c, d);
        return ss.str();
    }

    return "";
} 

void print(int n, int m){
    cout << "---" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << aa[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---" << endl;

}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t;
    cin >> t;
    while(t--){
        kk = 0;
        int n, m;
        cin >> n >> m;
        for(int i=0;i<n;i++){
            string tmp;
            cin >> tmp;
            for(int j=0;j<m;j++){
                aa[i][j] = tmp[j] - '0';
            }
        }
        string ans = "";
        for(int l=0;l<2;l++){
            for(int i=0;i<n-1;i+=1){
                for(int j=0;j<m-1;j+=1){                
                    if(l || aa[i][j] + aa[i][j+1] + aa[i+1][j] + aa[i+1][j+1] == 3){
                        ans += solve(i+1, j+1, aa[i][j], aa[i][j+1], aa[i+1][j], aa[i+1][j+1]);
                        aa[i][j] = aa[i][j+1] = aa[i+1][j] = aa[i+1][j+1] = 0;
                    }
                }
                // print(n, m); 
            }
        }


        cout << kk << endl;
        cout << ans;
    

    }
    return 0;
}