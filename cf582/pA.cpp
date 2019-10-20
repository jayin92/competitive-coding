#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int result = 2147483647;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        int temp = 0;
        for(int j=0;j!=i, j<n;j++){
            if(abs(a[i]-a[j]) % 2 == 1){
                temp ++;
            }
        }
        result = min(result, temp);
    }

    cout << result << endl;

}