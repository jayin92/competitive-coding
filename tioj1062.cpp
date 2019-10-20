#include <cstdio>
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
int X[100],Y[100],a,b,m,n,tmp,sum;
main(){
    scanf("%d%d",&n,&m);
    F(n)Fi(j,m)scanf("%d",&a),X[i]+=a,Y[j]+=a,sum+=a;
    sum=(sum+1)>>1;
    F(n){
        if(tmp+X[i]<sum)tmp+=X[i];
        else{
            printf("%d ",i+1);
            break;
        }
    }
    tmp=0;
    F(m){
        if(tmp+Y[i]<sum)tmp+=Y[i];
        else{
            printf("%d\n",i+1);
            break;
        }
    }
    scanf("%*d");
}