#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, x, now = 0;
    vector<int> station;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> x;
        // 不斷把新的車廂放進來，直到目標車廂出現為止。
        while (now < x) station.push_back(++now);
        // 計算目標車廂的位置。
        auto it = find(station.begin(), station.end(), x);
        int dist = station.end() - it;

        if (dist > M+1) {
            // 距離過遠代表得放超過 M 個車廂到上面，做不到。
            cout << "no" << endl;
            return 0;
        } else {
            // 否則就模擬把這節車廂開走。
            station.erase(it);
        }
    }
    cout << "yes" << endl;
    return 0;
}