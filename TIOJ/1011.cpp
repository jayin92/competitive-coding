// #include <bits/stdc++.h>
// #include <bitset>
// using namespace std;


// int main(){
//     int a, b;
//     int la , lb;
//     int result = 0;
    
//     cin >> a >> b;

//     if(b > a) swap(a, b);


//     if(a == 0 && b == 0){
//         cout << 0 << endl;
//         return 0;
//     }
//     if(b == 0){
//         b = 1;
//         result += 1;
//     }

//     la = floor(log(a) / log(2));
//     lb = floor(log(b) / log(2));

//     result += la - lb;

//     while(floor(log(a) / log(2)) != floor(log(b) / log(2))){
//         a = floor(a/2);
//     }


//     string aa, bb;
//     aa = bitset <64>(a).to_string();
//     bb = bitset <64>(b).to_string();


//     int temp = -1;
//     for(int i=0;i<64;i++){
//         if(aa[i] != bb[i]){
//             temp = 63-i;
//             break;
//         }
//     }
//     result += (temp + 1) * 2;

//     cout << result << endl;
// }

#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int ans = 0;
    while(a != b){
        if(a > b){
            a >>= 1;
            ans ++;
        } else{
            b >>= 1;
            ans ++;
        }
    }
    cout << ans << endl;

}