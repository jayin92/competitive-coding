#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    // 0: r, 1: s, 2: p
    // r: a, s: b, p: c
    unsigned long long res = 0;
    vector<char> play{'z'};
    char t;
    for(int i=1;i<=n;i++){
        cin >> t;
        if(t == 'r'){
             if(i <= k){
                 res += p;
                 play.push_back('p');
             } else {
                 if(play[i - k] == 'p'){
                     play.push_back('a');
                 } else {
                     res += p;
                     play.push_back('p');
                 }
             }
        }
        else if(t == 's'){
            if(i <= k){
                 res += r;
                 play.push_back('r');
             } else {
                 if(play[i - k] == 'r'){
                     play.push_back('b');
                 } else {
                     res += r;
                     play.push_back('r');
                 }
             }
        }
        else {
            if(i <= k){
                 res += s;
                 play.push_back('s');
             } else {
                 if(play[i - k] == 's'){
                     play.push_back('c');
                 } else {
                     res += s;
                     play.push_back('s');
                 }
             }
        }
    }
    cout << res << endl;


}