// 利用線段樹解決區間求和 & 單點修改
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node *lc, *rc;
    void pull(){
        val = lc -> val + rc -> val;
    }
};

const int n = 5;

int v[n + 1] = {0, 1, 2, 3, 4, 5};

Node* build(int L, int R){
    Node *node = new Node();
    if(L == R){
        node -> val = v[L];
    }
    int mid = (L+R) >> 1;
    node -> lc = build(L, mid);
    node -> rc = build(mid + 1, R);
    node -> pull();

    return node;
}

void modify(Node* node, int L, int R, int i, int d){
    if(L == R){
        assert(L == i);
        node->val += d;
        return;
    }
    int mid = (L + R) >> 1;
    if(i  <= mid){
        modify(node -> lc, L, mid, i, d);
    } else {
        modify(node -> rc, mid + 1, R, i ,d);
    }
    node -> pull();
}

int query(Node* node, int L, int R, int ql, int qr){
    if(ql > R || qr < L) return 0;
    if(ql <= L &&  R <= qr) return node -> val;
    int mid = (L + R) >> 1;
    return query(node -> lc, L, mid, ql, qr) +
           query(node -> rc, mid + 1, R, ql, qr);
}