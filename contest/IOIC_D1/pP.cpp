#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 10e6;
    vector<int> p;
    p.push_back(2);
    p.push_back(3);
    p.push_back(5);
    p.push_back(7);

    for(int i=11;i<n;i+=2){
        bool flag = false;
        cout << i << " ";
        for(int j:p){
            if(i % j == 0){
                flag = true;
                break;
            }
        }
        if(!flag) p.push_back(i);
    }
    cout << "tst" << endl;
    int s = p.size();
    for(int i=0;i<s-1;i++){
        if(p[i+1] > p[i] * 2) cout << p[i] << endl;
    }
}