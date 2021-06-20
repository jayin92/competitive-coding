#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp;
    for(int i=0;i<n;i++){
        cin >> a[i];
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        if(it == dp.end()) dp.push_back(a[i]);
        else *it = a[i];
    }

    cout << dp.size() << endl;
}