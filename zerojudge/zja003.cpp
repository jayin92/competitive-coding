// zj a003
#include <iostream>

using namespace std;

int main(){
    int a, b;
    int result;
    while(cin >> a >> b){        
        result = (a * 2 + b) % 3;
        switch(result){
            case 0:
                cout << "普通" << endl;
                break;
            case 1:
                cout << "吉" << endl;
                break;
            case 2:
                cout << "大吉" << endl;
                break;
        } 
    } 
}
