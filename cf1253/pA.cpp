#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
            c[i] = b[i] - a[i];
        }
        int tmp;
        bool start = false;
        bool end = false;
        bool yes = true;
        for(int i=0;i<n;i++){
            if(c[i] < 0){
                yes = false;
                break;
            }
            if(!start && c[i] > 0){
                start = true;
                tmp = c[i];
                continue;
            }
            if(!end && start){
                if(tmp != c[i]){
                    end = true;g    
                    continue;
                }
            }
            if(end && c[i] > 0){
                yes = false;
                break;
            }

        }
        if(yes) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}