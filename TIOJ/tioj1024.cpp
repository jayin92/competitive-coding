#include <bits/stdc++.h>

using namespace std;

struct P{
    int m, i, j;
};

P make(int m, int i, int j){
    P tmp;
    tmp.m = m;
    tmp.i = i;
    tmp.j = j;

    return tmp;
}

bool cmp(P r, P l){
    return r.m > l.m;
}

int main(){
    int n;
    while(true){
        cin >> n;
        vector<P> b;
        if(n == 0) return 0;
        int a[n][n];
        int tmp;
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> tmp;
                a[i][j] = tmp;
                b.push_back(make(tmp, i, j)); 
            }
        }
        sort(b.begin(), b.end(), cmp);
        int size = b.size();
        int size_ = b.size();
        while(size > 0){
            res += max(b[0].m, 0);
            int i = b[0].i;
            int j = b[0].j;
            for(int k=0;k<size_;k++){
                if(b[k].i == i || b[k].j == j){
                    size --;
                }
            }
           sort(b.begin(), b.end(), cmp);
        }

        cout << res << endl;

    }
}