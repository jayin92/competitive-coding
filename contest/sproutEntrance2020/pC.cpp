#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define ll long long

using namespace std;

int main(){
	ll n;
	cin >> n;
	vector<pii> s;
	ll a[n+2];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	ll cnt = 1;
	a[0] = a[n+1] = 0;
	ll tmp = a[0];
	s.push_back(make_pair(0, 1));
	for(ll i=1;i<=n;i++){
		if(a[i] == tmp){
			cnt ++;
		} else {
			s.push_back(make_pair(tmp, cnt));
			cnt = 1;
			tmp = a[i];
		}
	}
	s.push_back(make_pair(tmp, cnt));
	s.push_back(make_pair(0, 1));
	ll ans = -1;
	for(ll i=1;i<s.size();i++){
		if(s[i].first > s[i-1].first && s[i].first > s[i+1].first){
			ans = max(ans, s[i].second);
		}
	}
	cout << ans << endl;
	
}
