#include <bits/stdc++.h>

using namespace std;


void add(string a, string b){
    int MAX = max(a.size(), b.size());
    int c[a.size()], d[b.size()], rst[MAX+1];
    int j = 0;

    for(int i=a.size()-1;i>-1;i--){
        c[j] = (int)a[i] - (int)'0';
        j++;
    }
    j = 0;
    for(int i=b.size()-1;i>-1;i--){
        d[j] = (int)b[i] - (int)'0';
        j++;
    }

    int carry = 0;
    for(int i=0;i<MAX;i++){
        rst[i] = c[i] + d[i] + carry;
        cout << c[i] + d[i] + carry;
        carry = rst[i] / 10;
        rst[i] %= 10;
    }

    for(int i=MAX;i>-1;i--){
        cout << rst[i] << " ";
    }

}
int main(){
    string a, b;
    cin >> a;
    cin >> b;

    add(a, b);


}
