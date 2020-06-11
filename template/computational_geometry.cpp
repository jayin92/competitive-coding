#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<double, double> Pt;


Pt operator+(const Pt& p1, const Pt& p2){
    return Pt(p1.X + p2.X, p1.Y + p2.Y);
}
Pt operator­( const Pt& p1 , const Pt& p2 ){
    return Pt( p1.X - p2.X , p1.Y - p2.Y );
}
double operator*( const Pt& p1 , const Pt& p2 ){
    return p1.X * p2.X + p1.Y * p2.Y;
}

double operator^( const Pt& p1 , const Pt& p2 ){
    return p1.X * p2.Y - p1.Y * p2.X;
}

int main(){

}