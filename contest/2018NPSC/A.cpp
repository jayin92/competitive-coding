#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
	unsigned int A;
	int N,M;
	int c,Q,input,input2;
	scanf("%d %d %u",&N,&M,&A);
	bool dis[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			dis[i][j]=false;
		}
	}
	for(int m=0;m<M;m++){
		scanf("%d",&c);
		if(c==1){
			scanf("%d",&Q);
			int in[Q];
			for(int q=0;q<Q;q++){
				scanf("%d",&input);
				in[q]=(input^A)%N;
			}
			for(int q=0;q<Q;q++){
				for(int n=0;n<N;n++){
					bool inGroup=false;
					for(int q2=0;q2<Q;q2++){
						if(in[q2]==n){
							inGroup=true;
						}
					}
					if (inGroup){
						continue;
					}
					dis[in[q]][n]=true;
					dis[n][in[q]]=true;
				}
			}
		}
		
		else{
			scanf("%d %d",&input,&input2);

			if(dis[(input^A)%N][(input2^A)%N]&&((input^A)%N!=(input2^A)%N)){
				A=69069*A+1;
			}
			else{
				A=22695477*A+1;
			}
		}
	}
	printf("%u\n",A);

	return 0;
}
