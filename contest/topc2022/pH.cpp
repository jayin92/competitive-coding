#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int x = s.size();
    double lg6 = log10(6);
    double ans = (double)(x-1) / lg6 + 1;
    cout << ans << endl;
}