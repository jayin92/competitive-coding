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

void print_ans(int ans){
    if(ans == 0) cout << "none" << endl;
    else if(ans == 1) cout << "one" << endl;
    else cout << "both" << endl;
}


void solve(){
    int a, b, c, d, p, m, g;
    cin >> a >> b >> c >> d >> p >> m >> g;
    int ans = 0;
    p --; m--; g--;
    if(p % (a + b) < a) ans ++;
    if(p % (c + d) < c) ans ++;
    print_ans(ans);
    ans = 0;
    if(m % (a + b) < a) ans ++;
    if(m % (c + d) < c) ans ++;
    print_ans(ans);
    ans = 0;
    if(g % (a + b) < a) ans ++;
    if(g % (c + d) < c) ans ++;
    print_ans(ans);

    return;
}

int main(){
    #define name "pA"
    // #ifndef AXOLOTL
    // freopen(name".in", "r", stdin);
    // freopen(name".out", "w", stdout);
    // #endif
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
