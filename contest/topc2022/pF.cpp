#include <bits/stdc++.h>

using namespace std;

class Con{
public:
    string name;
    double pt, pu, rt, ru, f;
    double score;
    int ans = 0;
    Con(string _name, double _pt, double _pu, double _rt, double _ru, double _f){
        name = _name;
        pt = _pt;
        pu = _pu;
        rt = _rt;
        ru = _ru;
        f  = _f;
        score = (double)0.56 * ru + (double)0.24 * rt + (double)0.14 * pu + (double)0.06 * pt + (double)0.3 * f;
    }

    bool operator <(const Con &rhs){
        return score > rhs.score;
    }
};


int main(){
    int n;
    cin >> n;
    vector<Con> a;
    string s;
    double aa, b, c, d, e;
    for(int i=0;i<6;i++){
        cin >> s >> aa>> b >> c >> d >> e;
        a.push_back(Con(s, aa, b, c, d, e));
    }
    sort(a.begin(), a.end());
    int tmp = 0;
    for(int i=0;i<6;i++){
        if(a[i].name == "Taiwan") tmp = i;
    }
    int idx = 0;
    for(int i=0;i<n;i++){
        a[idx].ans ++;
        idx ++;
        idx %= 6;
    }
    cout << a[tmp].ans << endl;
    
}