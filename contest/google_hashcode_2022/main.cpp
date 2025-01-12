// :80 <enter>
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

class Project{
public:
    Project(string name, int num_day, int score, int best_before, int num_role, map<string, int> skills) : name(name), num_day(num_day), score(score), best_before(best_before), num_role(num_role), skills(skills)
    {}
    string name;
    int num_day;
    int score;
    int best_before;
    int num_role;
    map<string, int> skills;

    friend bool operator < (Project lhs, Project rhs){
        return lhs.num_role < rhs.num_role;
    }
};

class Person{
public:
    Person(string name, map<string, int> skills, int free_after): name(name), skills(skills), free_after(free_after)
    {}
    string name;
    map<string, int> skills;
    int free_after;
};


void print(Person a){
    cout << a.name << endl;
    for(auto i: a.skills){
        cout << i.X << " " << i.Y << endl;
    }
}

void solve(){
    int c, p;
    cin >> c >> p;
    string tmp;
    int t;
    vector<Person> per;
    vector<Project> pro;
    REP(i, c){
        cin >> tmp >> t;
        map<string, int> in;
        string skill_name;
        int level;
        REP(j, t){
            cin >> skill_name >> level;
            in[skill_name] = level;
        }
        per.push_back(Person(tmp, in, 0));
    }
    // for(auto i: per){
    //     print(i);
    // }
    REP(i, p){
        string pro_name;
        int d, s, b, r;
        cin >> pro_name >> d >> s >> b >> r;
        map<string, int> in;
        REP(j, r){
            string skill_name;
            int level;
            cin >> skill_name >> level;
            in[skill_name] = level;
        }
        pro.push_back(Project(pro_name, d, s, b, r, in));
    }
    sort(ALL(pro));
    // for(auto i: pro) print(i);
    vector<pair<string, vector<string>>> ans;
    int time = 0;
    for(int i=0;i<p;i++){
        Project cur = pro[i];
        vector<Person> tmp_ans;
        for(auto j: cur.skills){
            for(int k=0;k<c;k++){
                if(per[k].free_after <= time && per[k].skills[j.X] >= j.Y){
                    tmp_ans.push_back(per[k]);
                    break;
                }
            }
        }
        if((int)tmp_ans.size() == cur.num_role){
            // debug(cur.name);
            vector<string> names;
            for(auto &x: tmp_ans){
                x.free_after = time + cur.num_day;
                names.push_back(x.name);
            }
            ans.emplace_back(cur.name, names);
            // time += cur.num_day;
        }
    }
    cout << ans.size() << endl;
    for(auto i: ans){
        cout << i.X << endl;
        for(auto j: i.Y) cout << j << " ";
        cout << endl;
    }
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
