#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Point{
	ll x;
	ll y;
	
	
};

Point make(ll x, ll y){
		Point tmp;
		tmp.x = x;
		tmp.y = y;
		return tmp;
}

bool in(Point sc, Point su, Point t){
	return (min(sc.x, su.x) <= t.x && t.x <= max(sc.x, su.x) && min(sc.y, su.y) <= t.y && t.y <= max(sc.y, su.y));
}


int main(){
	ll n, c, d;
	Point bl = make(10e9+1, 10e9+1);
	Point tr = make(-1, -1);
	cin >> n >> c >> d;
	Point sc = make(c, d);
	Point a[n];
	for(int i=0;i<n;i++){
		cin >> a[i].x >> a[i].y;
		if(a[i].x < bl.x) bl.x = a[i].x;
		if(a[i].y < bl.y) bl.y = a[i].y;
		if(a[i].x > tr.x) tr.x = a[i].x;
		if(a[i].y > tr.y) tr.y = a[i].y;
	}
	int res = -1;
	Point loc;
	for(int j=0;j<n;j++){
		int tmp = 0;
		ll x = a[j].x;ll y=a[j].y;
		if(x != sc.x || y != sc.y){
			for(int i=0;i<n;i++){
				if(in(sc, a[i], make(x, y))){
					tmp ++;
				}
			}
		}
		if(tmp > res){
			res = tmp;
			loc = make(x, y);
		}
	}
	
	cout << res << endl;
	cout << loc.x << " " << loc.y << endl;
	return 0;
}

