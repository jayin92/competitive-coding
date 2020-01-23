#include <bits/stdc++.h>

using namespace std;

const int n = 10e6 + 4;
bool u[n/2];
vector<int> p;
int main(){
    int m, t, res;
    p.push_back(2);
    for(int i=1;i < n/2;i++){
        if(u[i] == false){
            p.push_back(i*2+1);
            for(int j=i;j < n/2;j+=i*2+1) u[j] = true;
        }
    }
    cin >> t;
    while(t--){
        cin >> m;
        res = upper_bound(p.begin(), p.end(), m) - p.begin();
        cout << res << endl;
    }
}