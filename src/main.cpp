#include <stdio.h>
#include <math.h>
int main(){
    int x,k,count=0;
    scanf("%d",&x);
    for (int t=2;t<=10000;t++){
         if(x==count){break;}
         k=1;
         if(t%2==1)
             for(;k<t;k++){
                 count++;
                 if(x==count){printf("%d/%d",k,t-k); break;}
             }
         else if (t%2==0)
             for(;k<t;k++){
                 count++;
                 if(x==count){printf("%d/%d",t-k,k); break;}
             }
    }        
}


