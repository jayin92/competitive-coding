// :19 <enter>
#include <bits/stdc++.h>
#include <sys/time.h>
#include <sys/resource.h>
#define X first
#define Y second
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void setstack(){
    // Set soft limit and hard limit to max
    const rlimit tmp {RLIM_INFINITY ,RLIM_INFINITY};
    setrlimit(RLIMIT_STACK ,&tmp);
}

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

vector<vector<bool>> a(105, vector<bool>(105));
int ans = 0;
int m, n;

bool check(int i, int j){
    if(i >= m || i < 0 || j >= n || j < 0) return false;
    else return true;
}

void find_loop(pii start, pii cur, vector<pii> path){
    // cerr << cur.X << " " << cur.Y << endl;
    if(start != cur) path.push_back(cur);
    if(a[cur.X][cur.Y] == 0 || a[start.X][start.Y] == 0) return;
    if(path.size() >= 2 && start == cur && a[start.X][start.Y] == 1) {
        ans ++;
        cout << endl;
        cout << start.X << " " << start.Y << endl;
        for(auto i: path){
            cout << i.X << " " << i.Y << endl;
            a[i.X][i.Y] = 0;
        }
        a[start.X][start.Y] = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout << a[i][j];
            }
            cout << endl;
        }
        return;
    }
    for(int k=0;k<8;k++){
        int nx = cur.X + dx[k];
        int ny = cur.Y + dy[k];
        if(check(nx, ny) && a[nx][ny] == 1){
            bool flag = true;
            for(auto i: path){
                if(i == make_pair(nx, ny)){
                    flag = false;
                    break;
                }
            }

            if(flag){
                pii nxt = make_pair(nx, ny);
                find_loop(start, nxt, path);
            }
        }
    }
}

void solve(){
    cin >> m >> n;
    char tmp;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> tmp;
            if(tmp == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    /*
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    */
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == 1){
                pii tmpp = make_pair(i, j);
                vector<pii> path;
                find_loop(tmpp, tmpp, path);
            }
            for(int ii=0;ii<m;ii++){
                for(int jj=0;jj<n;jj++){
                    // cout << a[ii][jj];
                }
                // cout << endl;
            }
        }
    }

    cout << ans << endl;
}

int main(){
    #define name "pF"
    /*
    #ifndef AXOLOTL
    freopen(name".in", "r", stdin);
    freopen(name".out", "w", stdout);
    #endif
    */
    static_assert(strlen(name));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
