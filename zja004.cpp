    // zj a004
    #include <iostream>

    using namespace std;

    int main(){
        int n;
        while(cin >> n){        
            if(n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)){
                cout << "閏年" << endl;
            } else {
                cout << "平年" << endl;
            }
        }
    }
