// zj a004
#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a[4];
        for(int i = 0;i<4;i++){
            cin >> a[i];
        }

        if(a[0]+a[2] == 2*a[1]){
            for(int i=0;i<4;i++){
                cout << a[i] << " ";
            }
            cout << a[3] + (a[1] - a[0]) << endl;
        } else {
            for(int i=0;i<4;i++){
                cout << a[i] << " ";
            }

            cout << a[3] * (a[1] / a[0]) << endl;
        }
    }
}
