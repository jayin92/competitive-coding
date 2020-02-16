#include <bits/stdc++.h>

using namespace std;

bool correct(string a){
    int br = 0;
    bool flag = true;
    for(char i:a){
        if(i == '(') br ++;
        if(i == ')') br --;
        if(br < 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    string a;
    cin >> n >> a;
    int br = 0;
    if(n == 0){
        cout << "Yes" << endl;
        return 0;
    }
    if(n % 2 == 1){
        cout << "No" << endl;
        return 0;
    }
    // if(correct(a)){
    //     cout << "Yes" << endl;
    //     cout << "test" << endl;
    //     return 0;
    // }
    br = 0;
    int min_ = 0;
    for(int i:a){
        if(i == '(') br++;
        if(i == ')') br--;
        min_ = min(br, min_);
    }
    if(br != 0){
        cout << "No" << endl;
        return 0;
    }
    if(min_ >= -1){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}