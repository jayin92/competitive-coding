#include <iostream>

using namespace std;

int main(){
    while(true){
        string s;
        cin >> s;
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                ans += n - i;
            }
            else{
                for(int j=i+1;j<n;j++){
                    if(s[j] == '1'){
                        ans += n - j;
                        break;
                    }
                }
            }            
        }
        cout << ans << endl;
    }
}