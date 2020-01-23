#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, target;
    string temp;
    while(cin>>n>>target && !cin.eof()){
        for(int i=0;i<n;i++){
            cin >> temp;
            if(i == n-target){
                cout << temp << endl;
            }
        }
    }

    return 0;
}