#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

typedef pair<int, int> pii;

const double INF = 0x3f3f3f3f3f3f3f3f;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pii> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i].X >> a[i].Y;
        }
        set<pair<double, double> > s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1, y1, x2, y2;
                x1 = a[i].X, y1 = a[i].Y;
                x2 = a[j].X, y2 = a[j].Y;
                double m, b;
                if(x2 == x1){
                    m = INF;
                    b = x1;
                }
                else{
                    m = (double)(y2-y1) / (double)(x2-x1);
                    b = y1 - m * x1;
                }               

                s.insert(make_pair(m, b));
            }
        }
        cout << s.size() << endl;
    }
}