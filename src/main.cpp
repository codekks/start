#include <stdio.h>
#include <math.h>


int main(){
    int m,n,k=0; 
    scanf("%d %d",&m,&n);
    if (m==2) {m++; printf("%d\n",2);}
    else if (m%2==0){m++;} 
    else if (m==3) {m=3; printf("%d\n",3);}
    int j=3;
    while(m<=n)
         {while(j<m)
            {if (m%j==0) {k=0; break;}
            else if (m%j!=0) {k=1;}
            j=j+2;}
         j=3;
         if (k==1) printf("%d\n",m);
         m=m+2;}
    

}


