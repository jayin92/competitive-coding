#include <iostream>

using namespace std;

int main(){
    char s[11] = "1234567890";
    int len = 12;
    for(int i=11;i>=0;i--){
        for(int j=0;j<=11;j++){
            cout <<s[(i+j)%len];
        }
        cout << endl;
    }

    return 0;
}
