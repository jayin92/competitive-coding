#include <iostream>

using namespace std;

int main(){
    int max = 1000000;
    int n;
    bool flag = 0;
    while(cin >> n){
        int cur = 2;
        flag = 0;   
        while(n != 1 && cur <= max){
            
            int count = 0;
            while(n % cur == 0){
                n /= cur;
                count ++;
            }
            if(count > 0){
                if(flag && count >= 1) cout << " * ";
                cout << cur;
                if(count > 1) cout << "^" << count;
                flag = 1;
            }
            cur ++;
        }
        cout << endl;
    }

}



