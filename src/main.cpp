#include <stdio.h>
#include <math.h>

/*int main(){
    int n,a=0,b=1;
    scanf("%d",&n);

    return 0;
    for (int i=1;a<n;i++)

        if (n<10) {printf("%d",n); break; }
        
        else if (n>=10) 
        {
            for (int j=0;j<i;j++) 
            {

                b=b*(10-j)/(j+1);
                a=a+b;
            }
        }
    if (a>=n) {a=a-b; printf("%d",a);}
} */

int main()
{
    int n, count = 10;
    scanf("%d", &n);
    if (n < 10)
        printf("%d", n);
    else if (n >= 10)
        for (int i = 10; i < 1000000; i++)
        {   int a = i;
            if (count == n)
                {break; printf("%d", i);}
            while (a >= 10)
            {
                if (a % 10 < (a / 10) % 10)
                count++;
            }
        }
}
