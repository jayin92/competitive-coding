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

struct Node{
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    ll val;
    
};

Node* del(Node* root, int key){
    if(!root) return nullptr;
    if(root -> val > key){
        root -> left = del(root -> left, key);
    } else if (root -> val < key){
        root -> right = del(root -> right, key);
    } else {
        if(!root -> left || !root -> right){
            root = (root -> left) ? root -> left : root -> right;
        } else {
            Node* cur = root -> right;
            while(cur -> left) cur = cur -> left;
            root -> val = cur -> val;
            root -> right = del(root -> right, cur -> val);
        }
    }
    return root;
}

void find_(Node* cur, ll n, ll &Min, ll &min_idx){
    if(cur == nullptr){
        return;
    }
    debug(cur -> val);
    if(cur -> val == n){
        min_idx = cur -> val;
        Min = 0;
        return;
    }
    if(Min > abs(cur -> val - n)){
        Min = abs(cur -> val - n);
        min_idx = cur -> val;
    }

    if(cur -> val < n){
        find_(cur -> right, n, Min, min_idx);
    } else {
        find_(cur -> left, n, Min, min_idx);
    }       
}


/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t;
    cin >> t;
    Node* root = new Node;
    bool flag =  true;
    while(t--){
        string a;
        ll n;
        cin >> a >> n;
        if(a == "insert"){
            if(flag){
                root -> val = n;
                flag = false;
            } else {
                Node* tmp = new Node;
                tmp -> val = n;
                Node* cur = root;
                while(true){
                    if(cur -> val > n){
                        if(cur -> left == nullptr){
                            cur -> left = tmp;
                            tmp -> parent = cur;
                            break;
                        } else {
                            cur = cur -> left;
                        }
                    } else {
                        if(cur -> right == nullptr){
                            cur -> right = tmp;
                            tmp -> parent = cur;
                            break;
                        } else {
                            cur = cur -> right;
                        }
                    }
                }
            }
        } else if(a == "delete"){
            del(root, n);
        } else if(a == "query"){
            ll min_diff = INF;
            ll ans1 = 0;
            ll ans2 = 0;
            Node* cur = root;
            while(cur != nullptr){
                ll diff = abs(n - cur -> val);
                if(diff < min_diff){
                    min_diff = diff;
                    ans1 = ans2 = cur -> val;
                } else if(diff == min_diff){
                    ans2 = cur -> val;
                }

                if(n < cur -> val){
                    cur = cur -> left;
                } else if(n > cur -> val){
                    cur = cur -> right;
                } else {
                    min_diff = 0;
                    ans1 = ans2 = cur -> val;
                    break;
                }
            }
            if(ans1 == ans2){
                cout << ans1 << endl;
            } else {
                cout << min(ans1, ans2) << " " << max(ans1, ans2) << endl;
            }
        }        
            
    }

    return 0;
}