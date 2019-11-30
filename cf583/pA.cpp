//https://codeforces.com/contest/1217/problem/A
// // #include <bits/stdc++.h>

// // using namespace std;

// // int main(){
// //     int n, e, d;
// //     cin >> n >> d >> e;
// //     // 1, 2, 5, 10, 20, 50, 100 dollar
// //     // 5, 10, 20, 50, 100, 200 euro   
// //     int result;
// //     int eu_temp = 0;
// //     while(eu_temp * e < n){
// //         eu_temp += 5;
// //     }
// //     if(eu_temp * e == n){
// //         cout << 0 << endl;
// //         return 0;
// //     } 
// //     int last = n - (eu_temp-5) * e;
// //     int dol_temp = 0;
// //     while(dol_temp * d < last){
// //         dol_temp += 1;
// //     }
// //     if(dol_temp * d == last){
// //         cout << 0 << endl;
// //     } else {
// //         result = last - (dol_temp-1) * d;
// //     }

// //     dol_temp = 0;
// //     while(dol_temp * d < n){
// //         dol_temp += 1;
// //     }
// //     if(dol_temp * d == n){
// //         cout << 0 << endl;
// //         return 0;
// //     } 
// //     last = n - (dol_temp-1) * d;
// //     eu_temp = 0;
// //     while(eu_temp * e < last){
// //         eu_temp += 5;
// //     }
// //     if(eu_temp * e == last){
// //         cout << 0 << endl;
// //     } else {
// //         cout << min(result, last - (eu_temp-5) * e) << endl;
// //     }

    
// // }

// #include <bits/stdc++.h>

// using namespace std;

// int main(){
//     int n, d, e;
//     cin >> n >> d >> e;
//     int dp[n+1];
//     dp[0] = 0;
//     for(int i=1;i<=n;i++){
//         if((dp[i-1] + 1) % 5 != 0){
//             dp[i] = dp[i-1] + 1;
//         } else {
//             dp[i] = min(((dp[i-1] + 1)) % e, (dp[i-1] + 1) % d);
//         }
//     }

//     cout << dp[n] << endl;
// }

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, d, e;
    cin >> n >> d >> e;
    int result = -1;
    for(int i=0;i<=n/e;i+=5){
        int last = n-(i * e);
        int temp = 0;
        if(last % d == 0){
            cout << 0 << endl;
            return 0;
        }
        int result_ = i*e + ((int)last/d)*d;
        result = max(result, result_);
    }
    cout << n - result << endl;
}