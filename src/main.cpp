#include <stdio.h>
#include <math.h>
int main(){
    int x,count;
    double p;
    scanf("%d",&x);
    for (double t=2.0;t<=10000;t++){
         for(double k=1.0;k<t;k++){
             p=k/(t-k);
             count++;
             if(x==count){break; printf("%f",p);}
             }
         if(x==count){break;}
     }
}
