#include <bits/stdc++.h>

using namespace std;

string print(vector<int> a){
    string res = "";
    for(int i:a){
        res += to_string(i);
        res += " ";
    }
    res += "\n";
    return res;
}

int main(){
    int n, m, k;
    cin >> n >> m;
    vector<int> y(n);
    vector<int> p(m);
    for(int i=0;i<n;i++) cin >> y[i];
    for(int i=0;i<m;i++) cin >> p[i];
    int round = 0;
    cin >> k;
    int a, b;
    stringstream ss;
    string res = "";
    string tmp;
    bool flag = false;
    for(int i=0;i<k;i++){
        round ++;
        cin >> a >> b;
        if(find(p.begin(), p.end(), a) != p.end()){
            p.erase(find(p.begin(), p.end(), a));
            if(find(y.begin(), y.end(), a) != y.end()) y.erase(find(y.begin(), y.end(), a));
            else y.push_back(a);
        }
        if(y.size() == 0 || p.size() == 0){
            flag = true;
            break;
        }
        if(find(y.begin(), y.end(), b) != y.end()){
            y.erase(find(y.begin(), y.end(), b));
            if(find(p.begin(), p.end(), b) != p.end()) p.erase(find(p.begin(), p.end(), b));
            else p.push_back(b);
        }
        if(y.size() == 0 || p.size() == 0){
            flag = true;
            break;
        }
        tmp = to_string(y.size());res += tmp;res += " ";res += print(y);
        tmp = to_string(p.size());res += tmp;res += " ";res += print(p);
    }
    cout << round << endl;
    if(flag == true){
        tmp = to_string(y.size());res += tmp;res += " ";res += print(y);
        tmp = to_string(p.size());res += tmp;res += " ";res += print(p);
    }
    cout << res;

}