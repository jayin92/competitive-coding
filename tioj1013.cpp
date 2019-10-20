#include <bits/stdc++.h>

using namespace std;

int main(){
    int f[2];
    int t;
    int s[2];
    int e[2];
    string map[10] = {
                        {"*****************"},
                        {"*...*.......**..*"},
                        {"**..*....*.*.*..*"},
                        {"*......*.**.**.**"},
                        {"*..**...**..**.**"},
                        {"**.....**..*.*..*"},
                        {"*....*..........*"},
                        {"*.....****.*...**"},
                        {"****.*.*........*"},
                        {"*****************"},
                    };
    cin >> f[0] >> f[1];
    cin >> t;
    cin >> s[0] >> s[1] >> e[0] >> e[1];

    queue <pair<int, int>> fire;
    fire.push(make_pair(f[0], f[1]));

    for(int i=1;i<=t;i++){
        queue <pair<int, int>> temp;
        while(!fire.empty()){
            map[fire.front().first][fire.front().second] = '*';
            if(fire.front().first - 1 >= 0 ) {
                temp.push(make_pair(fire.front().first-1, fire.front().second));
            }
            if(fire.front().first + 1 < 10){
                temp.push(make_pair(fire.front().first + 1, fire.front().second));
            }
            if(fire.front().second - 1 >= 0){
                temp.push(make_pair(fire.front().first, fire.front().second - 1));
            }
            if(fire.front().second + 1 < 17){
                temp.push(make_pair(fire.front().first, fire.front().second +- 1));
            }
            fire.pop();
        }
        fire = temp;
    }
    for(int i=0;i<10;i++){
        cout << map[i] << endl;
    }
}