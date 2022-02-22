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

bool is_number(string s){
    return all_of(s.begin(), s.end(), ::isdigit);
}

void solve(){
    string s;
    map<string, int> m;
    while(getline(cin, s)){
        if(s == "0") return;
        stringstream ss;
        ss << s;
        string tmp;
        int res
        while(ss >> tmp){
            if(tmp != "+"){
                if(is_number(tmp)){

                } else {

                }
            }

    }
}

int main(){
    #define name "pG"
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
