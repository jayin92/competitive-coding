#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000007;
map<long long, vector<string>> m;

long long hash_(string a){
    // set<int> s;
    // for(char i:a) s.insert(i - 'a');
    // int c = s.size();

    int n = a.size();
    int c = 26;
    long long tmp = 0;
    for(int i=0;i<n;i++){
        tmp += (a[i] - 'a') * pow(c, n - i - 1);
        tmp %= MOD;
    }

    return tmp;
}


void search(string s, int n){
    if(n == 0){
        m[hash_(s)].push_back(s);
        return;
    }
    for(char i='a';i<'z';i++){
        string tmp = s;
        tmp += i;
        search(tmp, n - 1);
    }
}


int main(){
    for(int k=1;k<=6;k++){
        m.clear();
        search("", k);
        for(auto i:m){
            if(i.second.size() >= 3){
                cout << i.first << endl;
                cout << "---" << endl;
                for(auto j: i.second){
                    cout << j << " ";
                }
                cout << endl << "---" << endl;
            }
        }
    }
}