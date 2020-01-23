#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    int a[m], b[n];
    for(int i=0;i<m;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    sort(a, a+m); sort(b, b+n);
    int x, y;
    x = y = 0;
    int ans = abs(a[0] - b[0]);
    while(x < m && y < n){
        ans = min(ans, abs(a[x] - b[y]));

        if(a[x] < b[y]){
            x ++;
        } else {
            y ++;
        }
    }

    cout << ans << endl;
}