// 最小圓覆蓋
#include <bits/stdc++.h>
#define pdd pair<double, double>
#define F first
#define S second

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    shuffle(a.begin(), a.end(), rng);
    for(auto i:a) cout << i << endl;
}   