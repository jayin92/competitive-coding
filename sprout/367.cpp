#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

struct Node{
    long long chg, data;
};

Node st[MAXN * 8];
long long v[MAXN];

void build(int l, int r, int i){
    if(l == r){
        st[i].data = v[l];
    } else {
        int lc = i * 2 + 1;
        int rc = i * 2 + 2;
        build(l, (l+r)/2, lc);
        build((l+r)/2+1, r, rc);
        st[i].data = max(st[lc].data, st[rc].data);
    }
}

void add(int a, int b, int i, int l, int r, int x){
    if(a <= l && r <= b) st[i].chg += x;
    else if(r < a || b < l) return;
    else{
        int mid = (l + r) / 2;
        int lc = i * 2 + 1;
        int rc = i * 2 + 2;
        add(a, b, lc, l, mid, x);
        add(a, b, rc, mid+1, r, x);
        st[i].data = max(st[lc].data + st[lc].chg, st[rc].data + st[rc].chg);
    }
}

int query(int a, int b, int i, int l, int r){
    // cout << l << " " << r << endl;
    // cout << a << " " << b << endl;
    // cout << "---" << endl;
    if(a <= l && r <= b){
        // cout << st[i].data + st[i].chg << endl;
        // cout << i << endl;
        return st[i].data + st[i].chg;
    }
    else if(r < a || b < l) return -1;
    else {
        int mid = (l + r) / 2;
        int lc = i * 2 + 1;
        int rc = i * 2 + 2;
        int x1 = query(a, b, lc, l, mid);
        int x2 = query(a, b, rc, mid+1, r);
        return max(x1, x2) + st[i].chg;
    }

}

int main(){
    int n, t;
    cin >> n >> t;
    for(int i=0;i<n;i++) cin >> v[i];
    build(0, n, 0);
    while(t--){
        int m;
        cin >> m;
        if(m == 1){
            int l_, r_, x_;
            cin >> l_ >> r_ >> x_;
            add(l_-1, r_-1, 0, 0, n, x_);
        } else {
            int l_, r_;
            cin >> l_ >> r_;
            cout << query(l_-1, r_-1, 0, 0, n) << endl;
        }
    }
}