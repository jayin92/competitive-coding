#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, max1, max2;

    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    max1 = a[0];
    int max1_index = 0;
    int max2_index = 0;
    for(int i=1;i<n;i++){
        if(a[i] > max1){
            max1 = a[i];
            max1_index = i;
        }
    }
    max2 = a[0];
    for(int i=1;i<max1_index;i++){
        if(a[i] > max2){
            max2 = a[i];
            max2_index = i;
        }
    }
    cout << max1_index - max2_index << endl;
}
