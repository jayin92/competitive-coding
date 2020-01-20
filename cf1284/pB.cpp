#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a[n];
    vector<long long> ma(n);vector<long long> mi(n);bool ac[n];vector<long long> acma;vector<int> acmi;
    for(long long i=0;i<n;i++){
        long long t, tmp;
        cin >> t;
        cin >> tmp;
        ma[i] = tmp;
        mi[i] = tmp;
        a[i].push_back(tmp);
        ac[i] = false;
        for(int j=1;j<t;j++){
            cin >> tmp;
            if(tmp > mi[i]) ac[i] = true;
            ma[i] = max(tmp, ma[i]);mi[i] = min(tmp, mi[i]);
            a[i].push_back(tmp);
        }
        if(t == 1) ac[i] = false;
        if(ac[i] == true){
            acma.push_back(ma[i]);
            acmi.push_back(mi[i]);
        }
        
    }
    long long res = 0;
    sort(mi.begin(), mi.end());
    sort(ma.begin(), ma.end());
    for(int i=0;i<n;i++){
        // cout << (lower_bound(mi.begin(), mi.end(), ma[i]) - mi.begin()) << " ";
        res += (lower_bound(mi.begin(), mi.end(), ma[i]) - mi.begin());
    }
    for(int i:acma){
        res += (n - (lower_bound(mi.begin(), mi.end(), i) - mi.begin()));
    }
    for(int i:acmi){
        res += (lower_bound(ma.begin(), ma.end(), i) - ma.begin());
    }
    cout << res << endl;

}