#include <stdio.h>
#include <math.h>


int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int ang[n+1]={0,};
    
    for (int i=2;i*i<=n;i++)
         if (ang[i]==0)
             for (int j=i*i;j<=n;j+=i)
                 ang[j]=1;
    ang[1]=1;
    for (int t=m;t<=n;t++)
         if (ang[t]==0) printf("%d\n",t);
    return 0;
}



