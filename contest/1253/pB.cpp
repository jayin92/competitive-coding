#include <bits/stdc++.h>
#define MAX 10e6+5
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int d = 0;
    int eve_ = 0;
    vector<int> eve;
    int sp[(int)MAX]= {0};
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt += (a[i]);
        eve_ ++;    
        if(a[i] > 0 && sp[a[i] - 1] % 2 == 0){
            if(sp[a[i] - 1] >= 2){
                cout << -1 << endl;
                return 0;
            }
            sp[a[i] - 1] ++;
        }
        if(a[i] < 0){
            if(sp[-a[i] - 1] % 2 == 0)
                cout << -1 << endl;
            else 
                sp[-a[i] - 1] ++;
        }
        if(cnt < 0){
            cout << -1 << endl;
            return 0;
        }
        if(cnt == 0 && a[i] < 0){
            d++;
            eve.push_back(eve_);
            eve_ = 0;
            cnt = 0;
            sp[(int)MAX] = {0};
        }
    }
    cout << d << endl;
    for(int i:eve){
        cout << i << " ";
    }
    cout << endl;
}