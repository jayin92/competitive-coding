#include <bits/stdc++.h>

using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) return 0;
        int a = n;
        int b = 0;
        for(int t=0;t<n-1;t++){
            for(int i=0;i<b;i++){
                cout << " "; 
            }
            for(int i=0;i<2;i++){
                cout << "*";
                for(int j=0;j<a-2;j++){
                    cout << " ";
                }
            }
            cout << "*" << endl;
            a--;
            b++;
        }
        for(int i=0;i<2*n-1;i++){
            cout << "*";
        }
        cout << endl;
        a++;
        b--;
        for(int t=0;t<n-1;t++){
            for(int i=0;i<b;i++){
                cout << " "; 
            }
            for(int i=0;i<2;i++){
                cout << "*";
                for(int j=0;j<a-2;j++){
                    cout << " ";
                }
            }
            cout << "*" << endl;
            a++;
            b--;
        }
    }
}