#include <stdio.h>
#include <math.h>


int main(){
    int n,count=9,a,result=1;
    scanf("%d",&n);
    if(n<10) printf("%d",n);
    else if(n>=10){
         for(int i=2;count<n;i++) {
             a=0;
             for (int u=1;u<=i;u++){
                 a=a+pow(10,u)*u; count++;
             }
             if(count==n) printf("%d",a); break;
             for(a;a<pow(10,i+1);a++){
                 if(count==n) printf("%d",a); break;
                 for(int j=1;j<i;j++){
                     int t=a;
                     if ((t % 10) < (t / 10) % 10) {
                         t=t/10; result=1; 
                        }
                     else if((t % 10) >= (t / 10) % 10){
                         a=a+pow(10,j)-a%pow(10,j); result=0; break;
                        } 
                    }
                 if(result == 1) count++;
                }
            }
        }
    }


