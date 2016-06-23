#include<stdio.h>
int main()
{
	//code
	int testcase;
	int i,j,a[4][4],n=4;
	int rowStart=0,colStart=0;
	int rowEnd=n-1,colEnd=n-1;
        scanf("%d",&testcase);
	while(testcase--)
	{
	    for(i=0;i<4;i++)
	    {
	        for(j=0;j<4;j++)
	        scanf("%d",&a[i][j]);
	    }
	    while(rowStart<=rowEnd&&colStart<=colEnd)
            {
              int i=rowStart,j=colStart;
              for(j=colStart;j<=colEnd;j++)
                 printf(" %d",a[i][j]);

              for(i=rowStart+1,j--;i<=rowEnd;i++)
                 printf(" %d",a[i][j]);

              for(j=colEnd-1,i--;j>=colStart;j--)
              printf(" %d",a[i][j]);
        
              for(i=rowEnd-1,j++;i>=rowStart+1;i--)
               printf(" %d",a[i][j]);   
                     
               rowStart++;colStart++;rowEnd--;colEnd--;
            }
           
	    
	    
	}
	return 0;
}
