// #include <iostream>
// #include <stack>
// #include <utility>

// using namespace std;

// int main(){
//     int n, m;
//     cin >> n >> m;
//     int a[200][200];
//     int b[200][200];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin >> a[i][j];
//         }
//     }
//     for(int j=0;j<m;j++){
//         if(a[0][j] == 1){
//             b[0][j] = 1;
//         }
//     }
//     for(int i=1;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(a[i][j] == 1) b[i][j] = b[i-1][j] + 1;
//             else b[i][j] = 0;
//         }
//     }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout << b[i][j] << " ";
//         }
//         cout << endl;
//     }
//     int max = -1000;
//     int last = 0;
//     for(int i=2;i<n;i++){
//         stack <pair<int, int>> s;
//         s.push(make_pair(0, b[i][0]));
//         for(int j=1;j<m;j++){
//             if(b[i][j] > s.top().second){
//                 s.push(make_pair(j, b[i][j]));
//             }
//             else if(b[i][j] < s.top().second){
//                 while(b[i][j] <= s.top().second && !s.empty()){                    
//                     if((j - s.top().first)*s.top().second > max){
//                         max = (j - s.top().first)*s.top().second;
//                     }
//                     last = s.top().first;
//                     s.pop();
//                     if(s.empty()){
//                         s.push(make_pair(0, b[i][j]));
//                         break;
//                     }
//                     if(b[i][j] > s.top().second){
//                         s.push(make_pair(last, b[i][j]));
//                         break;
//                     }
                    
//                 }
                
//             }
//         }

//     }
//     cout << max << endl;
// }

#include<bits/stdc++.h>
using namespace std;
int rec[209][209];
int r[209];
int main()
{
    int n,m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {   
        for(int j = 1; j <= m; j++)
        {
            cin >> rec[i][j];
            if(rec[i][j]){
                r[j] += 1;
            } else {
                r[j] = 0;
            }
            for(int t = j, rr = r[j]; t >= 1 && rec[i][t]; t-- ,rr = min(r[t],rr))
                ans = max(ans,rr*(j-t+1));
        }
        
    }
    cout << ans << '\n';    
}