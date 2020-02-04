#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n;
	cin >> n;
	ll a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	ll Max, Min;
	ll ans = 0;
	priority_queue<ll, greater<int>()> ma;
	for(ll l=0;l<n;l++){
		
		for(ll r=l;r<n;r++){			
			Max = max(a[r], Max);
			Min = min(a[r], Min);			
			if(Min * 2 >= Max){
				ans ++;
			}
		}
	}
	cout << ans << endl;
}
