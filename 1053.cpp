#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    if(a<b){
        swap(a,b);
    }

    if(a%b == 0){
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}
