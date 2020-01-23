#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        int seq[35] = {0};
        unsigned long long a[n];
        bool flag = false;
        for(int i=0;i<n;i++){
            cin >> a[i];
            a[i] = log2(a[i]);
            seq[a[i]] ++;
        }
        for(int i=0;i<11;i++){
            seq[i+1] = seq[i+1] + (int)(seq[i]/2);
        }
        if(seq[11] > 0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}