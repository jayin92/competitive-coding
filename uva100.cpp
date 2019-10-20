#include <bits/stdc++.h>

using namespace std;

int f(int n, int m, int step){
    if(n == 1){
        return step;
    }
    else if(n % 2 == 0) return f(n/2, m, ++step);
    else return f(3*n+1, m, ++step);
}


int main(){
    int n, m;
    while(!cin.eof()){
        cin >> n >> m;
        if(cin.eof()) break;
        int step = 0;
        int n_ = n;
        int m_ = m;
        if(n > m){
            swap(n, m);
        }
        for(int i=n;i<=m;i++){
            step = max(step, f(i, i, 1));
        }

        cout << n_ << " " << m_ << " " << step << endl;
    }
}