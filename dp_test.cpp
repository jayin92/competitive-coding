#include <bits/stdc++.h>

const int X = 8, Y = 8;
int a[X][Y] = {{0,4,1,8,9,-3,4,9}, {1,2,9,7,8,2,5,8},{3,1,9,-3,7,2,4,7},{2,4,9,2,0,3,0,6},{3,6,9,1,1,1,4,5},{4,2,9,-2,2,-3,5,4},{5,0,9,1,7,1,4,3},{2,3,1,3,3,9,5,2}};
int c[X][Y];

using namespace std;

int main()
{
    // [Initial]
    c[0][0] = a[0][0];
    for (int i=1; i<X; i++)
        c[i][0] = c[i-1][0] + a[i][0];
    for (int j=1; j<Y; j++)
        c[0][j] = c[0][j-1] + a[0][j];

    // [Compute]
    for (int i=1; i<X; i++)
        for (int j=1; j<Y; j++)
            c[i][j] = max(c[i-1][j], c[i][j-1]) + a[i][j];

    // 輸出結果
    cout << "由(0,0)走到(7,7)的最小總和" << c[7][7];
//  cout << "由(0,0)走到(7,7)的最小總和" << c[X-1][Y-1];

    int x, y;
    while (cin >> x >> y)
        cout << "由(0,0)走到(x,y)的最小總和" << c[x][y];
}
