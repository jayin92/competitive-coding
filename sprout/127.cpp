#include <bits/stdc++.h>

using namespace std;

// int mm[4][5] = {
//     {74, 59, 36, 28, 51},
//     {36, 63, 15, 25, 17},
//     {71, 64, 95, 43, 56},
//     {72, 62, 30, 24, 74},
// };

// int GetVal(int p, int q){
//     return mm[p-1][q-1];
// }

// void Report(int n){
//     cout << "Report(" << n << ")" << endl;
// }


int ans[1000003];

int pos(int l, int r, int n){
    int tmp = -1;
    int idx = l;
    int val;
    for(int i=l;i<=r;i++){
        val = GetVal(n, i);
        if(val > tmp){
            tmp = val;
            idx = i;
        }
    }

    return idx;
}


void solve1(int l1, int r1, int l2, int r2){
    if(l1 == r1){
        ans[l1] = pos(l2, r2, l1);
        return;
    } else if(l1 > r1) return;

    int mid = (l1 + r1) >> 1;
    ans[mid] = pos(l2, r2, mid);

    solve1(l1, mid-1, l2, ans[mid]-1);
    solve1(mid+1, r1, ans[mid]+1, r2);
}

void solve(int n, int m){
    solve1(1, n, 1, m);
    for(int i=1;i<=n;i++){
        Report(ans[i]);
    }
}

int main(){
    solve(4, 5);
}