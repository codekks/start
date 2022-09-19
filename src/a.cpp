
#include <stdio.h>

int main() {
    int a;
    scanf("%d",&a);
    while(a>1){
        if(a%2==0)
        a=a/2;
        else if (a%2==1) a=a-1;
    }
    printf("%d",a);
    return 0;
}
