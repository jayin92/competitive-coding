// ioi 2013 art class, 利用相鄰像素明度 = (r+g+b) / 3

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

typedef long long ll;
using namespace std;

int main(){
	int H,W;
	while(scanf("%d %d",&H,&W)!=EOF){
		ll a1,a2,a3,b1,b2,b3;
		ll total = 0;
		for(int g=0;g<H;g++){
			scanf("%lld %lld %lld",&a1,&a2,&a3);
			ll teamto=(a1+a2+a3)/3;
			for(int h=1;h<W;h++){
				scanf("%lld %lld %lld",&b1,&b2,&b3);
				total += abs(teamto - (b1+b2+b3)/3);
				teamto = (b1+b2+b3)/3;
			}
		}
		total = total /(H*(W-1));
		if(total<=2) puts("4");
		else if(total<=6) puts("1");
		else if(total<=20) puts("2");
		else puts("3");
	}
	return 0;
}