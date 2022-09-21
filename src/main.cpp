#include <stdio.h>
#include <math.h>
#include <chrono>
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
    if (n <= 10)
        printf("%d", n);
    else if (n > 10) {
        for (long int i = 11; i < 10000000000; i++)
        {   
            int result = 1;
            long int a = i;
            
            while (a >= 10)
            {
                if (a % 10 < (a / 10) % 10) {
                    a=a/10; 
                } else {
                    result = 0;
                    break;
                }
            }
            if(result == 1) {
                count++;
            }
            if (i>987654321) {printf("-1");break;}
            if (count == n)
                {printf("%d", i);break;}
        }
    }
}
