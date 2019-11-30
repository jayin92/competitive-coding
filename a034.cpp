#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while (cin >> n){
        vector<int> ans;
        while(n != 0){
            ans.push_back(n % 2);
            n /= 2;
        }
        for(int i=ans.size()-1;i>=0;i--){
            cout << ans[i];
        }
        cout << endl;
    }
    
}