#include <stdio.h>

int isprime(int N)
{
    int i;
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(i=3; i*i<=N; i+=2)
    {
        if(!(N%i))
            return 0;
    }
    return 1;
}
int main()
{
    int testcase,n,i,j,prime=0,sum=0,max=0;
    int a[5000];



        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);


        for(i=n;i>0;i--)
        if(isprime(i))
        break;

        prime=i;
        printf("%d",prime);

        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=i;j<prime+i&&j<n;j++)
            { 
              sum=sum+a[j];
              printf("\ni:%d,j:%d",i,j);
              printf("\n%d",sum);
            }
            printf("\n");
           // if(j==n)
           // break;  
            if(sum>max)
             max=sum;
        }
        printf("%d",max);

    return 0;
}
