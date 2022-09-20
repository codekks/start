#include <stdio.h>

int main() {
    int a,n;
    scanf("%d/n",&a);
    int array[a];
    for(int i=0;i<a;i++) scanf("%d",array+i);
    int max=array[0];
    int min=array[0];
    for (int j=1;j<=a;j++) {
        if (array[j]>max) max=array[j];
        else if (array[j]<min) min=array[j];
        };
    n=max*min;
    printf("%d",n);
    return 0;
}


