#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    string c;
    bool flag = true;
    for(int i=a;i<=b;i++){
        c = to_string(i);
        flag = true;
        bool di[10] = {0};
        for(int j=0;j<c.size();j++){
            if(di[c[j]-'0'] == 1){
                flag = false;
                continue;
            } else {
                di[c[j]-'0'] = 1;
            }
        }
        if(flag){
            cout << i << endl;
            return 0;
        }

    }
    cout << -1 << endl;
}