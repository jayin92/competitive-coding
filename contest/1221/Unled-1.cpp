#include <bits/stdc++.h>
#include <string>

using namespace std;

int num(int a){
    int i,j=1;
    for(i=0;i<a;i++){
        j*=2;
    }
    return j;
}

int main(){
    int b,i,j,c=0;
    cin >> b;
    int a[b];
    for(i=0;i<b;i++){
        cin >> a[i];
    }
    for(i=0;i<b;i++){
        for(j=0;j<=11;j++){
            if(a[i]==1){
                c+=num(j);
                break;
            }
            a[i]=a[i]/2;
        }
    }
    if(c>=2048){
        cout << "possible";
    }
    else{
        cout << "impossible";
    }
}

