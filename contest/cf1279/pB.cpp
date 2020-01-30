// #include <bits/stdc++.h>

// using namespace std;

// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         long long n, s;
//         cin >> n >> s;
//         int a[n];
//         vector<vector<int>> sum(n+1);
//         cin >> a[0];
//         int res = -1;
//         int res_ = -1;
//         for(int i=1;i<n+1;i++){
//             sum[i].push_back(a[0]);
//         }
//         for(int i=1;i<n;i++){
//             cin >> a[i];
//             for(int j=0;j<n+1;j++){
//                 if(i != j){
//                     if(sum[j].size() == 0) sum[j].push_back(a[i]);
//                     else sum[j].push_back(sum[j][sum[j].size()-1] + a[i]);
//                 }
//             }
            
//         }
//         // cout << "test" <<endl;
//         // cout << sum[n][n-1] << endl;
//         if(sum[n][n-1] <= s){
//             cout << 0 << endl;
//             continue;
//         }
//         // for(int i=0;i<n;i++){
//         //     for(int j=0;j<n;j++){
//         //         cout << sum[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }
//         for(int i=0;i<n;i++){
//             // for(int j=0;j<n-1;j++){
//             //     cout << sum[i][j] << " ";
//             // }
//             // cout << "||";
//             auto tmp = upper_bound(sum[i].begin(), sum[i].end(), s);
//             int tmp_ = tmp - sum[i].begin();
//             if(tmp_ > res){
//                 res = tmp_;
//                 res_ = i+1;
//             }
//         }
//         cout << res_ << endl;
//     }
//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n , s, res;
        res = 0;
        int sum = 0;
        cin >> n >> s;
        long long a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
        }
        if(s >= sum){
            cout << 0 << endl;
            continue;
        }   
        int ress = -2;
        for(int i=0;i<n;i++){
            int tmp = 0;
            int res_ = 0;
            for(int j=0;j<n;j++){
                if(i != j){
                    tmp += a[j];
                    res_ ++;
                }
                if(tmp > s){
                    break;
                }
            }
            if(res_ - 1 > ress){
                ress = res_ - 1;
                res = i+1;
            }
        }
        cout << res << endl;
        
    }
}