#include <stdio.h>
#include <math.h>


int main(){
    int n,count=9,a,t,result=1;
    scanf("%d",&n);
    if(n<10) printf("%d",n);
    else if (n==1022) printf("%lu",9876543210);
    else if (n>1023) printf("%d",-1);
    else if (n>=10){
         for(int i=2;i<10;i++) {
             a=0;
             for (int u=1;u<i;u++){
                 a=a+pow(10,u)*u;}
             while(a<pow(10,i)){
                 t=a;
                 for(int j=1;j<i;j++){
                     if ((t % 10) < (t / 10) % 10) {
                     t=t/10; result=1;}
                     else if((t % 10) >= (t / 10) % 10){
                     int p=pow(10,j);
                     a=(a/p+1)*p-1; 
                     result=0; 
                     t=a;
                     break;}  
                }
                 if(result == 1) {count++;}
                 if(count==n) {printf("%d",a); break;}
                 a++;
                }
             if(count==n) break;
            }
        }
    }


/*int main(){
    int t,n,count=9,a=0,result=1,i=2;
    scanf("%d",&n);
    for (int u=1;u<i;u++){
        a=a+pow(10,u)*u;}
    while(a<pow(10,i)){
        if(count==n) {printf("%d",a-1); break;}
        t=a;
        for(int j=1;j<i;j++){
             if ((t % 10) < (t / 10) % 10) {
                 t=t/10; result=1; 
                }
             else if((t % 10) >= (t / 10) % 10){
             int p=pow(10,j);
             a=(a/p+1)*p-1; 
             result=0; 
             t=a;
             break;
             }  
        if(result == 1) {count++;}
        }
        a++;
    }
}
*/

