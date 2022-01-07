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

void solve(){
    int e, f, c;
    cin >> e >> f >> c;
    int ans = 0;
    int n = e + f;
    while(n >= c){
        ans += n / c;
        n = n % c + n / c;
    }
    cout << ans << endl;
}

int main(){
    #define name "pD"
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
