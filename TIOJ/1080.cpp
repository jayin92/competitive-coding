//TODO: 離散化

#include <bits/stdc++.h>

using namespace std;

struct BIT{
    int sz;
    vector<int> dat;
    void init(int _sz){
        sz = _sz;
        dat.assign(sz+1, 0);
    }
    
    void upd(int id, int x){
        for(int i=id;i<=sz;i += i&-i){
            dat[i] += x;
        }
    }
    int sum(int id){
        int res = 0;
        for(int i=id;i>0;i -= i&-i){
            res += dat[i];
        }
        return res;
    }
};

int main(){
    BIT bit;
    long long a[100010];
    int _case = 0;
    while(true){
        int n;cin >> n;
        if(n == 0) return 0;
        _case ++;
        bit.init(100010);
        long long ans = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            ans += bit.sum(a[i - 1]) - bit.sum(a[i]);
            bit.upd(a[i], 1);
        }
        printf("Case #%d: %lld\n", _case, ans);
    }
}