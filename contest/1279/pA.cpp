// #include <bits/stdc++.h>

// using namespace std;

// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         long long a, b, c;
//         cin >> a >> b >> c;
//         long long m = min(min(a, b), c);
//         a -= m;b -= m;c -= m;
//         if(a == 0){
//             if(abs(b - c) <= m){
//                 cout << "Yes" << endl;
//             } else {
//                 cout << "No" << endl;
//             }
//         } else if (b == 0){
//             if(abs(a - c) <= m){
//                 cout << "Yes" << endl;
//             } else {
//                 cout << "No" << endl;
//             }
//         } else if(c == 0){
//             if(abs(a - b) <= m){
//                 cout << "Yes" << endl;
//             } else {
//                 cout << "No" << endl;
//             }
//         }
//     }
//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long  a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);
        a[2] -= a[1];
        long long tmp = abs(a[2] - a[0]);
        a[2] -= a[0];
        if(a[2] == 0 || a[2] == 1){
            cout << "Yes" << endl;
        } else if(a[2] < 0){
            if(a[0] <= tmp){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
}