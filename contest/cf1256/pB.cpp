#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    int a[200];
    while(q--){
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int tmp = n - 1;
        int swp = 1;
        while(true){
            // cout << swp << endl;
            bool sorted = true;
            for(int i=0;i<n;i++){
                if(a[i] == swp && i+1 == swp){
                    swp++;
                    break;
                }
                if(a[i] == swp && i != 0){
                    swap(a[i-1], a[i]);
                    tmp--;
                    break;
                }
            }
            for(int i=0;i<n;i++){
                if(a[i] != i+1) sorted = false;
            }
            if(sorted) break;
            if(tmp == 0) break;            
        }
        for(int i=0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << endl;        
    }
}