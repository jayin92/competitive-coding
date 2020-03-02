#include <bits/stdc++.h>

using namespace std;

int main(){
    stringstream ss;
    string a;
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        getline(cin, a);
        ss.clear();
        ss << a;
        bool if_  = 1;
        string ifs = "";
        string thens = "";
        bool not_ = 0;
        while(ss >> a){
            if(a == "IF"){
                continue;
            }
            if(a == "THEN"){
                if_ = 0;
                continue;        
            }
            if(if_){
                if(a == "and"){
                    thens += "or ";
                } else if(a == "or"){
                    thens += "and ";
                } else if(a != "not" && !not_){
                    thens += ("not " + a + " ");
                    not_ = 0;
                } else if(a != "not" && not_){
                    thens += (a + " ");
                    not_ = 0;
                } else {
                    not_ = 1;
                }
            }
            if(!if_){
                if(a == "and"){
                    ifs += "or ";
                } else if(a == "or"){
                    ifs += "and ";
                } else if(a != "not" && !not_){
                    ifs += ("not " + a + " "); 
                    not_ = 0;
                } else if(a != "not" && not_){
                    ifs += (a + " ");
                    not_ = 0;
                } else {
                    not_ = 1;
                }
            }
        }
        cout << "IF " << ifs << "THEN " << thens.substr(0, thens.size()-1) << endl;
    }    
}