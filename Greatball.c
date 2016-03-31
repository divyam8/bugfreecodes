#include<stdio.h>
#include<string.h>
int main()
{
   int t;
   int q,a,b,i,j,n,temp,z[1001][2];
     int max=0;
     int count;
  scanf("%d",&t);
  while(t>0)
  {
	 // z[1001][2]={0,0};
	  memset(z, 0, sizeof z);
	  max=0;
	  count=0;
     scanf("%d",&n);
	 for(i=0;i<n;i++)
	 {
	     scanf("%d%d",&z[i][0],&z[i][1]);
	     
     } //accepting the element
     
     
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
			if(z[j][0]>z[j+1][0])
			{
            temp=z[j][0];
            z[j][0]=z[j+1][0];
            z[j+1][0]=temp;


			temp=z[j][1];
            z[j][1]=z[j+1][1];
            z[j+1][1]=temp;
			}
        }
            
    } //sorting of time intervals
  
  
   

  for(i=0;i<n;i++)
      {
        count=1;
        for(j=0;j<n;j++)
        {
             if(j==i)  
			 continue;
             if(z[j][0]<z[i][1]&&z[j][1]>=z[i][1])
              { 
				  count++; 
			 }               
        }
        if(count>=max)
          max=count;
     }
        printf("%d\n",max);
t--; 
}


return 0;
}
