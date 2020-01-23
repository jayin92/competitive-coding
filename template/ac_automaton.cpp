#include <bits/stdc++.h>
#define W 26

using namespace std;

struct AC{
    vector<array<int,W>> ch;
    vector<int> cnt;
    AC(){
        extend();
    }
    void extend(){
        ch.push_back(array<int, W>());
        cnt.push_back(0);
    }
    int getnext(int u, int c){
        if(ch[u][c] == 0){
            extend();
            ch[u][c] = (int)cnt.size() - 1;
        }
        return ch[u][c];
    }
    void insert(const string &a){
        int u = 0;
        for(auto c:a){
            u = getnext(u, c-'a');
        }
        cnt[u] ++;
    }
    vector<int> f;
    void build_fail(){
        f = vector<int>(ch.size(), 0);
        queue<int> q;
        for(int i=0;i<W;i++) if(ch[0][i]) q.push(ch[0][i]);
        while(!q.empty()){
            const int u = q.front();
            q.pop();
            for(int i=0;i<W;i++){
                if(ch[u][i]){
                    int v = f[u];
                    while(v&&!ch[v][i]) v = f[v];
                    if(ch[v][i]) v = ch[v][i];
                    f[ch[u][i]] = v;
                    cnt[ch[u][i]] += cnt[v];
                    q.push(ch[u][i]);
                }
            }
        }
    }
    void match(const string &a){
        int u = 0;
        for(int i=0;i<(int)a.size();i++){
            while(u&&!ch[u][a[i] - 'a']) u = f[u];
            if(ch[u][a[i] - 'a']) u = ch[u][a[i] - 'a'];
            if(cnt[u] > 0) cout << "find " << cnt[u] << " matches at pos " << i << endl;
        }
    }
};


int main(){
    AC ac;
    int n;cin >> n;
    while(n--){
        string b;
        cin >> b;
        ac.insert(b);
    }
    ac.build_fail();
    string a; 
    cin >> a;
    ac.match(a);
    return 0;

}