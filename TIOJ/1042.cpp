// // #include <bits/stdc++.h>

// // using namespace std;

// // struct P{
// //     int m, i, j;
// // };

// // P make(int m, int i, int j){
// //     P tmp;
// //     tmp.m = m;
// //     tmp.i = i;
// //     tmp.j = j;

// //     return tmp;
// // }

// // bool cmp(P r, P l){
// //     return r.m > l.m;
// // }

// // int main(){
// //     int n;
// //     while(true){
// //         cin >> n;
// //         vector<P> b;
// //         if(n == 0) return 0;
// //         int a[n][n];
// //         int tmp;
// //         int res = 0;
// //         for(int i=0;i<n;i++){
// //             for(int j=0;j<n;j++){
// //                 cin >> tmp;
// //                 a[i][j] = tmp;
// //                 b.push_back(make(tmp, i, j)); 
// //             }
// //         }
// //         sort(b.begin(), b.end(), cmp);
// //         int size = b.size();
// //         int size_ = b.size();
// //         while(size > 0){
// //             res += max(b[0].m, 0);
// //             int i = b[0].i;
// //             int j = b[0].j;
// //             for(int k=0;k<size_;k++){
// //                 if(b[k].i == i || b[k].j == j){
// //                     size --;
// //                 }
// //             }
// //            sort(b.begin(), b.end(), cmp);
// //         }

// //         cout << res << endl;

// //     }
// // }

// #include <bits/stdc++.h>

// using namespace std;

// int res = 0;
// int n;
// int a[105][105];
// void tra(int i, int sum, vector<int> out){
//     if(i != n - 1){
//         for(int k=0;k<n;k++){
//             if(find(out.begin(), out.end(), k) == out.end()){
//                 auto t = out;
//                 t.push_back(k);
//                 tra(i+1, sum+max(0, a[i][k]), t);
//             }
//         }
//     } else {
//         for(int k=0;k<n;k++){
//             if(find(out.begin(), out.end(), k) == out.end()){
//                 res = max(res, sum+a[i][k]);
//                 return;
//             }
//         }
//     }
// }

// int main(){
//     while(true){
//         cin >> n;
//         res = 0;
//         if(n == 0) return 0;
//         for(int i=0;i<n;i++)
//             for(int j=0;j<n;j++)
//                 cin >> a[i][j];
//         vector<int> t;
//         tra(0, 0, t);
//         cout << res << endl;
        
//     }
// }

#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    while(true){
        cin >> n;
        long long a[n][n];
        long long b[n];
        unsigned long long res = 0;
        if(n == 0) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> a[i][j];
                if(a[i][j] < 0) a[i][j] = 0;
            }
        }
        
        for(int i=0;i<n;i++){
            b[i] = i;
            res += a[i][i];
        }
        // cout << res << endl;
        while(true){
            int swap_ = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(a[j][b[i]] + a[i][b[j]] > a[i][b[i]] + a[j][b[j]]){
                        res += (a[j][b[i]] + a[i][b[j]]) - (a[i][b[i]] + a[j][b[j]]);
                        swap(b[i], b[j]);
                        swap_ ++;
                    }
                }   
            }
            if(swap_ == 0) break;
        }
    
        cout << res << endl;
    }
    
        
    
}