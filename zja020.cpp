#include <iostream>
#include <string>
using namespace std;
int main()
{
  long long int a[26]={1,10,19,28,37,46,55,64,39,73,82,2,11,20,48,29,38,47,56,65,74,83,21,3,12,30};
  string b;
  while (cin >> b) {
    int c, d[9]={0}, num=0, ans;
    c=a[b[0]-65];
    for (int i=1;i<10;i++) {
      if (i==9) {
        d[num]=b[i]-48;
        break;
      }
      d[num]=(b[i]-48)*(9-i); num++;
    }
    ans=c+d[0]+d[1]+d[2]+d[3]+d[4]+d[5]+d[6]+d[7]+d[8];
    ans%10==0 ? cout << "real" << endl : cout << "fake" << endl;
  }
}