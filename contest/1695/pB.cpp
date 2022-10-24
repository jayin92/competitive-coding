#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        if(n == 1){
            cout << "Mike" << endl;
            continue;
        }
        if(n % 2 == 0){
            int mike_min = 1e9 + 5;
            int joe_min = 1e9 + 5;
            int mike_idx = 1;
            int joe_idx = 2;
            for(int i=1;i<=n;i+=2){
                if(mike_min > a[i]){
                    mike_idx = i;
                    mike_min = a[i];
                }
            }
            for(int i=2;i<=n;i+=2){
                if(joe_min > a[i]){
                    joe_idx = i;
                    joe_min = a[i];
                }
            }
            if(mike_min == joe_min){
                if(mike_idx > joe_idx){
                    cout << "Mike" << endl;
                } else {
                    cout << "Joe" << endl;
                }
            } else if(mike_min > joe_min){
                cout << "Mike" << endl;
            } else {
                cout << "Joe" << endl;
            }
        } else {
            cout << "Mike" << endl;
        }
    }
}