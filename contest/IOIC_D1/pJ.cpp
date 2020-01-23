#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void go() {
    ll a, b, c; cin >> a >> b >> c;
    set<ll> st; //randomly generate 5 numbers
    while (st.size() != 5) {
        st.insert(rand() % 1000 + 3000);
    }
    for (ll mod: st) {
        if ((a % mod + b % mod) % mod != c % mod) {
            cout << "Noooo" << endl;
            return;
        }
    }
    cout << "Yuuki" << endl;
}

int main () {
    srand(time(NULL));
    int T; cin >> T;
    while (T--) {
        go();
    }
}