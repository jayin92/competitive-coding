#include <bits/stdc++.h>
using namespace std;

int ans[100005];

void solve(int l, int r){
    int len = r - l + 1;
    if(len == 2){
        ans[l] = 1;
        ans[l+1] = 2;
        return;
    } else if(len == 3){
        ans[l] = 2;
        ans[l+1] = 1;
        ans[l+2] = 3; 
        return;
    }

    if(len % 2 == 0){
        solve(l, l + len/2 - 1);
        for(int i=l+len/2;i<=r;i++){
            ans[i] = 2 * ans[i-len/2];
        }
        for(int i=l;i<l+len/2;i++){
            ans[i] = 2 * ans[i] - 1;
        }

    } else {
        len += 1;
        solve(l, l + len / 2 - 1);
        ans[r] = 2 * ans[r-len/2+1] - 1;
        for(int i=l+len/2-1;i<r;i++){
            ans[i] = 2 * ans[i-len/2+1] - 1;
        }
        for(int i=l;i<l+len/2-1;i++){
            ans[i] = 2 * ans[i];
        }
    }

    return;
}



/********** Good Luck :) **********/
int main () {
    int n;
    cin >> n;
    if(n == 1){
        cout << "1";
        return 0;
    }
    solve(0, n-1);
    for(int i=0;i<n;i++){
        cout << ans[i];
        if(i != n - 1) cout << " ";
    }

    return 0;
}