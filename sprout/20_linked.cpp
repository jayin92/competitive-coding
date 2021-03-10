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
const ll MAXN = 1000005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


struct Per{
    int team;
    int id;
    Per* pre = nullptr;
    Per* nxt = nullptr;
    Per* pre_team = nullptr;
    Per* nxt_team = nullptr;

};

void print(Per* root){
    while(root != nullptr){
        cout << root -> id << " ";
        root = root -> nxt;
    }
    cout << endl;
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t = 1;
    int n;
    while(cin >> n){
        cout << "Line #" << t++ << endl;
        // vector<Per*> member[n];
        vector<Per*> person(MAXN, nullptr);
        vector<Per*> tail(n, nullptr);
        Per* root = new Per;
        Per* last = new Per;
        root -> id = -1;
        root -> team = -1;
        last -> id = -1;
        last -> team = -1;
        root -> nxt = last;
        last -> pre = root;
        int m;
        for(int i=0;i<n;i++){
            cin >> m;
            for(int j=0;j<m;j++){
                Per* tmp = new Per;
                cin >> tmp -> id;
                tmp -> team = i;
                person[tmp -> id] = tmp;
            }
        }

        string s;

        while(cin >> s){
            if(s == "STOP")
                break;
            
            if(s == "ENQUEUE"){
                int i;
                cin >> i;
                if(person[i] != nullptr){
                    Per* cur = person[i];
                    Per* cur_tail = tail[cur -> team];
                    if(cur_tail == nullptr || cur_tail == last){
                        last -> pre -> nxt = cur;
                        cur -> pre = last -> pre;
                        last -> pre = cur;
                        cur -> nxt = last;                    
                    } else {
                        cur -> pre = cur_tail;
                        if(cur_tail != nullptr){
                            cur_tail -> nxt -> pre = cur;
                            cur -> nxt = cur_tail -> nxt;
                        }
                        cur_tail -> nxt = cur;                                        
                    }
                    tail[person[i] -> team] = cur;
                } else {
                    Per* cur = new Per;
                    cur -> id = i;
                    cur -> team = -2;
                    last -> pre -> nxt = cur;
                    cur -> pre = last -> pre;
                    last -> pre = cur;
                    cur -> nxt = last;     
                }
            } else if(s == "DEQUEUE"){
                Per* cur = root -> nxt;
                if(cur == tail[cur -> team]){
                    tail[cur -> team] = nullptr;
                }
                cout << cur -> id << endl;                
                root -> nxt = cur -> nxt;
                cur -> nxt -> pre = root;
            }
            
            // print(root);

        }


        
    }

    return 0;
}