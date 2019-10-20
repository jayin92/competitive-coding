// zj a006
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int a, b, c;
    while(cin >> a >> b >> c){
        int D = pow(b,2) - 4*a*c;
        if(D>0){
            printf("Two different roots x1=%d , x2=%d\n", (int)(-b + sqrt(D))/(2*a), (int)(-b - sqrt(D))/(2*a));

        } else if(D == 0){
            cout << "Two same roots x=" << (int)-b / (2*a) << endl;
        } else {
            cout << "No real root" << endl;
        }
    }
}
