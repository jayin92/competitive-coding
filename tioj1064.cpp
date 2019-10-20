#include <iostream>
#include <vector>
#include <string>
#define MAX 50;
using namespace std;

vector<int> string_to_arr(string a){

    int len = a.size();
	
    vector<int> rst;
    rst.clear();
    for(int i=len-1;i>=0;i--){
        rst.push_back(a[i]-48);
    }
    for(int i=0;i<len;i++){
    	cout << rst[i] << " ";
	}
	return rst;
}

vector<int> multone(string a, char b){
    int carry = 0;
    vector <int> result;
    int b_ = b - '0';
    for(int i=a.size()-1;i>=0;i--){
        int a_ = a[i] - '0';
        int temp = a_ * b_ + carry ;
        result.push_back(temp % 10);
        carry = temp / 10;
    }
    result.push_back(carry);
    return result;
}

void multiply(string a, string b){
    vector <unsigned long long> result;
    int last_digit = -1;
    for(int i=b.size()-1;i>=0;i--){
        last_digit ++;
        vector<int> temp = multone(a, b[i]);
        for(int i=0;i<temp.size();i++){
            if((i + last_digit) > (int)result.size() - 1){
                result.push_back(temp[i]);
            } else {
                result[i+last_digit] += (temp[i]);
            }
        }
    }
    int carry = 0;
    for(int i=0;i<result.size();i++){
        int temp_ = result[i];
        result[i] = (result[i]+carry) % 10;
        carry = (temp_+carry) / 10;
    }
    if(carry != 0) cout << carry;
    bool flag = true;
    for(int i=result.size()-1;i>=0;i--){
        if(result[i] != 0 && flag){
            cout << result[i];
            flag = false;
        } else if(!flag){
            cout << result[i];
        }
    }
    cout << endl;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    multiply(a, b);

    return 0;
}
