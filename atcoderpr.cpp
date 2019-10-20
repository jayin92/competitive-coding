#include <bits/stdc++.h>

using namespace std;

bool cmp(char a, char b){
    cout << "?" << " " << a << " " << b << endl;
    char in;
    cin >> in;
    if(in == '<'){
        return 1;
    }
    return 0;
}

int main(){
    int n, q;
    cin >> n >> q;
    char a[n];
    for(int i=0;i<n;i++){
        a[i] = 'A' + i;
    }
    sort(a, a+n, cmp);

    cout << "! ";
    for(int i=0;i<n;i++){
        cout << a[i];
    }
    cout << endl;

    return 0;
}