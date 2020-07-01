#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

struct Node{
    int l, r;
    int lc, rc;
    int data;
};

int a[MAXN];
Node st[MAXN * 2];


int stptr = 1;

void build(int l, int r, int idx){
    st[idx].l = l, st[idx].r = r;
    if(l == r-1){
        st[idx].data = a[l];
    } else {
        int lc = st[idx].lc = stptr ++;
        int rc = st[idx].rc = stptr ++;
        build(l, (l+r)/2, lc);
        build((l+r)/2, r, rc);
        st[idx].data = min(st[lc].data, st[rc].data);
    }
}

void mod(int x, int v, int idx){
    if(st[idx].l == st[idx].r - 1){
        st[idx].data = v;
    } else {
        int mid = (st[idx].l + st[idx].r) / 2;
        int lc = st[idx].lc;
        int rc = st[idx].rc;

        if(x < mid) mod(x, v, lc);
        else mod(x, v, rc);
        st[idx].data = min(st[lc].data, st[rc].data);
    }
}

int query(int l, int r, int idx){
    // cout << l << " " << r << " " << idx << endl;
    if(st[idx].l == l && st[idx].r == r){
        return st[idx].data;
    } else {
        int mid = (st[idx].l + st[idx].r) / 2;
        int lc = st[idx].lc;
        int rc = st[idx].rc;
        if(r <= mid) return query(l, r, lc);
        else if(l >= mid) return query(l, r, rc);
        else return min(query(l, mid, lc), query(mid, r, rc));
    }

}

int main(){
    int n, t;
    cin >> t >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    build(0, n, 0);
    // cout << st[0].l << " " << st[0].r << endl;
    while(t--){
        int m, x, y;
        cin >> m >> x >> y;
        if(m == 1){
            cout << query(x, y+1, 0) << endl;
        } else {
            mod(x, y, 0);
        }
    }
}