#include <bits/stdc++.h>

using namespace std;

int main(){
    string a;
    while (cin >> a)
    {
        bool flag = false;
        string b = "";
        for(int i=a.size()-1;i>=0;i--){
             b += a[i];
        }
        cout << stoi(b) << endl;
    }
    
}