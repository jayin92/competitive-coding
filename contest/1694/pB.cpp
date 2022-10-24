#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        string s;
        cin >> n >> s;
        long long ans = n;
        bool pre = s[0] - '0';
        for(int i=1;i<n;i++){
            if(pre != s[i] - '0'){
                pre = s[i] - '0';
                ans += i;
            }
        }
        cout << ans << endl;
    }
}