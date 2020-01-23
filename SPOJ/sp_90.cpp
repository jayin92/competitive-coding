/* sprout online judge problem 90*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n, m, success;
    int box[100005], tree[100005];
    success = 0;
    cin >> t;
    for(int c=0;c<t;c++){
        cin >> n >> m;

        for(int i=0;i<n;i++){
            cin >> box[i];
        }

        for(int i=0;i<m;i++){
            cin >> tree[i];
        }
        sort(box, box+n);
        sort(tree, tree+m);

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(tree[j] <= box[i] && tree[j]!=0){
                    box[i] -= tree[j];
                    tree[j] = 0;
                    success ++;
                }
            }
        }
        cout << success << endl;
    }

}
