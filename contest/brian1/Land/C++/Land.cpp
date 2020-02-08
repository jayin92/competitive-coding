#include "Land.h"

//----do not modify above----
#define ll long long
#define M 8
#include <iostream>

using namespace std;

// ll sum = area(0, 0, M, M);
ll T = 0, B = M, R = 0, L = M;
void tratb(ll b, ll t, ll sum){
	cout << B << " " << T << endl;
	if(t - b == 0) return;
	ll mid = (t + b) / 2;
	cout << b << " " << t << " " << mid << endl;
	ll p1 = area(0, b, M, mid);
	ll p2 = area(0, mid, M, t);
	cout << "Area:" << p1 << " " << p2 << endl;
	if(p1 == 0 && p2 != 0){
		if(t - b == p2){
			if(t > T) T = t;
			return;
		} 
		tratb(mid, t, p2);
	} else if(p1 != 0 && p2 == 0){
		if(t - b == p1){
			if(b < B) B = b;
			return;
		} 
		tratb(b, mid, p1);
	} else {
		tratb(b, mid, p1);
		tratb(mid, t, p2);
	}
}

void trarl(ll l, ll r, ll sum){
	ll mid = (l + r) / 2;
	ll p1 = area(l, 0, mid, M);
	ll p2 = area(mid, 0, r, M);
	if(p1 == 0 && p2 != 0){
		if(r - l == p2){
			if(r > R) R = r;
			return;
		} 
		trarl(mid, r, p2);
	} else if(p1 != 0 && p2 == 0){
		if(r - l == p1){
			if(l < L) L = l;
			return;
		} 
		trarl(l, mid, p1);
	} else {
		trarl(l, mid, p1);
		trarl(mid, r, p2);
	}
}

rectangle find_rectangle(int subtask){
	ll r, l, t, b, mid, p1, p2;
	l = 0;
	b = 0;
	r = M+1;
	t = M+1;
	cout << L << " " << B << " " << R << " " << T << endl;
	tratb(b, t, 100);
	cout << "---" << endl;
	trarl(l, r, 100);
	cout << L << " " << B << " " << R << " " << T << endl;
	
 	rectangle res;
	res.a = L;res.b = B;res.c = R;res.d = T;
	
	return res;
}

//----do not modify below----

#ifndef EVAL
namespace{
	constexpr int _MAX_C = 1000000000;
	constexpr int _MAX_NUM_QUERY = 128;
	int _count=0,_a,_b,_c,_d;
	bool _valid(int x){
		if(x<0||x>_MAX_C) return 0;
		return 1;
	}
	int _max(int a,int b){
		if(a>b) return a;
		return b;
	}
	int _min(int a,int b){
		if(a<b) return a;
		return b;
	}
	void _input(int *x){
		scanf("%d",x);
	}
	void _wrong_answer(const char *MSG) {
		printf("Wrong Answer: %s\n", MSG);
		exit(0);
	}
	void _Accepted(const int c){
		printf("Accepted: %d\n",c);
	}
}

long long area(int x1, int y1, int x2, int y2){
	++_count;
	if(_count>_MAX_NUM_QUERY)
		_wrong_answer("too many queries");
	if(!_valid(x1)||!_valid(x2)||!_valid(y1)||!_valid(y2))
		_wrong_answer("invalid query");
	if(!(x1<x2&&y1<y2))
		_wrong_answer("invalid query");
	int ml=_max(x1,_a),mr=_min(x2,_c);
	int md=_max(y1,_b),mu=_min(y2,_d);
	if(ml>=mr||md>=mu) return 0;
	return (long long)(mr-ml)*(long long)(mu-md); 
}

int main() {
	int t,mx=0,subtask=0;
	rectangle tmp;
	_input(&t),_input(&subtask);
	while(t--){
		_count=0;
		_input(&_a),_input(&_b),_input(&_c),_input(&_d);
		tmp=find_rectangle(subtask);
		if(tmp.a!=_a||tmp.b!=_b||tmp.c!=_c||tmp.d!=_d)
			_wrong_answer("incorrect place");
		else
			mx=_max(mx,_count);
	}
	_Accepted(mx);
}
#endif
