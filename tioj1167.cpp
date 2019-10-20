#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){
        if(!a && !b) return 0;
        vector <int> bike;
        for(int i=0;i<a;i++){
            int temp;
            cin >> temp;
            bike.push_back(temp);
        }

        sort(bike.begin(), bike.end());

        cout << bike[a-b] << endl;
    }
}