#include <bits/stdc++.h>

using namespace std;

struct folder{
    string name;

    folder* parent = nullptr;
    vector<folder*> child;

    int path = 0;
};

void print(vector<folder*> a){
    for(auto i:a){
        cout << i -> name << " ";
    }
    cout << endl;
}

int len(string name){
    int res = 0;
    for(char i:name){
        res += i - 'a';
    }

    return res;
}

int main(){
    int q;
    cin >> q;
    folder root;
    root.name = "";
    root.path = 0;
    root.parent = nullptr;
    folder* current = &root;

    while(q--){
        int op;
        cin >> op;
        if(op == 0){
            if(current -> parent != nullptr)
                current = current -> parent;
        }
        else if(op == 1){
            string name;
            cin >> name;
            bool flag = false;
            for(int i=0;i<current -> child.size();i++){
                if(current -> child[i] -> name == name){
                    current = current -> child[i];
                    flag = true;
                    break;
                }
            }
            if(!flag){
                folder *new_folder = new folder;
                new_folder -> parent = current;
                new_folder -> name = name;
                new_folder -> path = current -> path + len(name);
                current -> child.push_back(new_folder);
                current = new_folder;

            }
        } else if(op == 2){
            string name;
            cin >> name;
            bool flag = false;
            for(int i=0;i<current -> child.size();i++){
                if(current -> child[i] -> name == name){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                folder *new_folder = new folder;
                new_folder -> parent = current;
                new_folder -> name = name;
                new_folder -> path = current -> path + len(name);
                current -> child.push_back(new_folder);
            }
        } else if(op == 3){
            cout << current -> path << endl; 
        } 
        
    }
    
}