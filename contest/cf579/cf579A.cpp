#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        map <int, int> st;
        vector <int> area;
        bool flag = false;
        int n;
        cin >> n;
        int a[n*4];
        for(int i=0;i<4*n;i++){
            cin >> a[i];
            st[a[i]] ++;
        }
        for(pair<int, int> i:st){
            if(i.second < 2){
                st.erase(i.first);
            }
        }
        for(auto i:st){
            for(auto j:st){
                if(i.first >= j.first){
                    area.push_back(i.first * j .first);
                }
            }
        }

        for(int i:area){
            cout << i << endl;
            int temp = 0;
            for(auto j:st){
                for(auto k:st){
                    if(j.first >= k.first){
                        if(j.first * k.first == i){
                            temp ++;
                            j.second -= 2;
                            k.second -= 2;
                        }
                        if(temp == n && !flag){
                            cout << "YES" << endl;
                            flag = true;
                        }
                    }       
                }
            }
        }
        if(!flag) cout << "NO" << endl;
    }

}