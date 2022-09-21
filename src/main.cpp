#include <stdio.h>
#include <math.h>
int ang(int t){
    int b1=log(t);
    int b=floor(b1);
    char s[b+1];
    int c;
    sprintf(s,"%d",t);
    for (int i=0;i<b;i++)
         if (s[i]>s[i+1]) {c=1;}
         else break; c=0;
    return c;
    }

int main() {
    int n,count=1;
    scanf("%d",&n);
    for(int a=1;a<=1000000;a++)
        if (count==n) {break; printf("%d",a);}
        else if (count!=n)
            {if (ang(a)==1) count ++;}
    return 0;
}


 