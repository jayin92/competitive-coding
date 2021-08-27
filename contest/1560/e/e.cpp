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

string del(string s, char a){
    string res = "";
    int sz = s.size();
    for(int i=0;i<sz;i++){
        if(s[i] != a){
            res += s[i];
        }
    }
    return res;
}

void solve(){
    string s;
    cin >> s;
    int sz = s.size();
    vector<bool> chk(26, false);
    vector<int> cnt(26, 0);
    vector<vector<int>> pre(sz, vector<int>(26, 0));
    vector<int> order;
    for(int i=sz-1;i>=0;i--){
        if(chk[s[i]-'a'] == false){
            chk[s[i]-'a'] = true;
            order.pb(s[i]-'a');
        }
        cnt[s[i]-'a']++;
    }
    pre[0][s[0]-'a'] = 1;
    for(int i=1;i<sz;i++){
        for(int j=0;j<26;j++) pre[i][j] = pre[i-1][j];
        pre[i][s[i]-'a'] ++;
    }
    int szz = order.size();
    debug(cnt);

    for(int i=szz-1;i>=0;i--){
        debug(cnt[order[i]], (szz-i));
        if(cnt[order[i]] % (szz-i) != 0){
            cout << -1 << endl;
            return ;
        }
        cnt[order[i]] /= (szz-i);
    }
    for(int i=0;i<sz;i++){
        bool flag = true;
        for(int j=0;j<26;j++){
            if(pre[i][j] != cnt[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            string ans = s.substr(0, i+1);
            string tmp = ans;
            int sidx = i+1;
            bool flag1 = false;
            for(int k=szz-1;k>=0;k--){
                tmp = del(tmp, order[k]+'a');
                debug(tmp);
                if(tmp != s.substr(sidx, tmp.size())){
                    flag1 = true;
                    break;
                }
                sidx += tmp.size();
            }
            if(flag1){
                continue;
            }
            cout << ans  << " ";
            for(int j=szz-1;j>=0;j--){
                cout << (char)(order[j] + 'a');
            }
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
    
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}