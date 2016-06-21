#include <stdio.h>
#include <stdlib.h>

void count(int n)
{
    int i=1,count=0,j,flag,temp;
     for(i=1;i<=n;i++)
        {
          flag=0;
          temp=i;
        while(temp>0)
        {
            j=temp%10;

            if(j==0||j==6||j==7||j==8||j==9)
            {
                flag=1;
                break;
            }
            temp=temp/10;

        }
        if(flag==0)
        count++;
        }

         printf("%d\n",count);

}
int main()
{
    int testcase,n;
    scanf("%d",&testcase);
    while(testcase>0)
    {
        scanf("%d",&n);
        count(n);
        testcase--;
    }
    
    return 0;
}






