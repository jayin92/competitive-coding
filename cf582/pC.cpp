#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    vector <vector<int>> a(10);
    a[0] = {0};
    a[1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    a[2] = {0, 2, 4, 6, 8};
    a[3] = {0, 3, 6, 9, 2, 5, 8, 1, 4, 7};
    a[4] = {0, 4, 8, 2, 6};
    a[5] = {0, 5};
    a[6] = {0, 6, 2, 8, 4};
    a[7] = {0, 7, 4, 1, 8, 5, 2, 9, 6, 3};
    a[8] = {0, 8, 6, 4, 2};
    a[9] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int sum[10] = {0};
    for(int i=0;i<10;i++){
        for(int j:a[i]){
            sum[i] += j;
        }
    }
    while(q--){
        unsigned long long n, m;
        unsigned long long result;
        cin >> n >> m;
        unsigned long long d = n / m;
        unsigned long long r = d % a[m%10].size();

        result = sum[m % 10] * (unsigned long long)(d / a[m%10].size());
        for(unsigned long long i=0;i<=r;i++){
            result += a[m % 10][i];
        }

        cout << result << endl;
    }
}