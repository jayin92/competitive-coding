#include <bits/stdc++.h>

using namespace std;



vector<int> cur;
vector<vector<int>> ans;
int sz;
void solve(vector<int> src, int idx, int sum){
    cout << "===" << endl;
    cout << << idx << " " << sum << endl;
    cout << "===" << endl;
    if(sum == 0){
        ans.push_back(cur);
        return;
    } else if(sum < 0 || idx >= sz) {
        return;
    } else {
        solve(src, idx+1, sum);
        if(sum >= src[idx]){
            cur.push_back(src[idx]);
            solve(src, idx+1, sum-src[idx]);
            cur.pop_back();
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    solve(candidates, 0, target);
    
    return ans;
}

int main(){
    vector<int> a = {2, 3, 6, 7};
    
    auto res = combinationSum(a, 7);

    for(auto i: res){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}