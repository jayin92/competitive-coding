#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define X first
#define Y second
using namespace std;

int main(){
	ll q, t, x, c;
	cin >> q;
	c = 0;
	bool flag = true;
	vector<pll> li;
	ll ans = 0;
	ll tmp = 0;
	while(q--){
		cin >> t >> x;
		if(t == 1){
			if(flag){
				tmp = x;
				flag = false;
			} else {
				tmp = max(tmp, x);
			}
		} else if(t == 2){
			li.push_back(make_pair(c, c+tmp));
			tmp = 0;
			c += x;			
			flag = true;
		}
	}
	li.push_back(make_pair(c, c+tmp));
	ll sz = li.size();
	ll ma = 0;
	for(int i=0;i<sz;i++){
		if(li[i].Y <= ma){			
			continue;
		} else if(li[i].X >= ma){
			ma = li[i].Y;
			ans += (li[i].Y - li[i].X) * (li[i].Y - li[i].X);
		} else {			
			ans += ((li[i].Y - li[i].X) * (li[i].Y - li[i].X)) - ((ma - li[i].X) * (ma - li[i].X));
			ma = li[i].Y;
		}
	}
	cout << ans << endl;
}
