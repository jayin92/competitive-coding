#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

class Point{
public:
    int dis;
    int idx;
    Point(int _dis, int _idx){
        dis = _dis;
        idx = _idx;
    }
    bool operator <(const Point& rhs){
        if(dis != rhs.dis){
            return dis < rhs.dis;
        }
        return idx < rhs.idx;
    }
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<Point> a;
    vector<int> d(n+1);
    int x;
    for(int i=1;i<=n;i++){
        cin >> x;
        a.push_back(Point(x, i));
        d[i] = x;
    }
    sort(a.begin(), a.end());
    vector<int> s;
    vector<pii> ans;
    if(a[0].dis != 0 || a[0].dis == a[1].dis){
        cout << -1 << endl;
        return 0;
    }
    vector<int> tmp;
    tmp.push_back(a[0].idx);
    for(int i=1;i<n;i++){
        if(a[i-1].dis != a[i].dis){
            for(auto j: tmp) s.push_back(j);
            sort(s.begin(), s.end());
            tmp.clear();
        }
        tmp.push_back(a[i].idx);
        
        int l, r;
        auto it = upper_bound(s.begin(), s.end(), a[i].idx);
        if(it == s.begin()) l = *s.rbegin();
        else l = *prev(it);
        if(it == s.end()) r = *s.begin();
        else r = *it;

        if(d[l] == a[i].dis - 1){
            ans.push_back({l, a[i].idx});
        } else if(d[r] == a[i].dis - 1){
            ans.push_back({r, a[i].idx});
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    for(auto i: ans){
        cout << i.first << " " << i.second << endl;
    }
}