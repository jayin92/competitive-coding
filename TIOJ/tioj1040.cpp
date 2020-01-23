#include <bits/stdc++.h>

using namespace std;
int count = 0;

void cal(int p, int q){
    extern int count;
    if(p%q == 0){
        cout << p/q;
        for(int i=1;i<count;i++){
            cout << "}";
        }
        cout << endl;
        return;
    }
    count ++;
    if(count > 1){
        cout << "{";
    }
    cout << p/q << "+1/";
    return cal(q, p%q);

}

int main(){
    extern int count;
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        count = 0;
         int p, q;
        cin >> p >> q;
        cout << p << "/" << q << " = ";
        cal(p, q);
    }
   
}