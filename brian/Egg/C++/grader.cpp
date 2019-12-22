#include "Egg.h"

long long _M, _h;

int _count = 0;

bool is_broken(long long k){
	_count++;
	if(_count > 60){
		printf("Wrong Answer: too many queries\n");
		exit(0);
	}
	if(k > _M){
		printf("Wrong Answer: invalid broken query\n");
		exit(0);
	}
	return k > _h;
}

int main() {
	long long hl, ret;
	ret = scanf("%lld %lld", &_M, &_h);
	hl = height_limit(_M);
	if(hl == _h)
		printf("Accept: %d\n", _count);
	else
		printf("Wrong Answer: incorrect height\n");
}
