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
    ll d, r, t;
    cin >> d >> r >> t;
    ll sum = r + t;
    ll i;
    for(i=3;i<200000;i++){
        ll tmp = (i + 3LL) * (i-2LL) / 2LL + (i+d+4LL) * (i+d-3LL) / 2LL;
        if(tmp == sum) break;
    }
    
    cout << r - (i+d+4LL) * (i+d-3LL) / 2LL << endl;
}

int main(){
    #define name "pE"
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
