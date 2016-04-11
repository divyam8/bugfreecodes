#include <stdio.h>
#define U 0
#define N 9
bool issafe(int grid[N][N], int row,int col,int value); 

bool solvesudoku(int grid[N][N],int row,int col)
{
   int value;
   if(row<9&&col<9)
    {
        if(grid[row][col]) 
        {
            if((col+1)<9) return solvesudoku(grid, row, col+1);
            else if((row+1)<9) return solvesudoku(grid, row+1, 0);
            else return true;
        }    
     
       else
        {
		   for(value=1;value<=N;value++)  //for finding all the cases from 1 to 9 
		   {
		   	  if (issafe(grid,row,col,value))
		   	  {
		   	  	grid[row][col]=value;

		   	  	if(solvesudoku(grid,row,col)) //recursive call
		   	  		return true;
		        else   
		   	     grid[row][col]=0;
		   	  }
		   }
		   return false;
		}
    }
   else
   	return true;
}
bool issafe(int grid[N][N],int row,int col,int value)
{
   	   int rowstart=row-row%3;
       int colstart=col-col%3;

       for(int i=0;i<9;i++)
       {
       	  if(grid[row][i]==value) 
            return false;
          if(grid[i][col]==value)
          	return false;
          if(grid[rowstart+(i%3)][colstart+i/3]==value)
          	return false;
       }
       return true;
}
int main(int argc, char const *argv[])
{
    int testcase;
    int grid[9][9],row,col,i,j,num;
	char a[82];
    scanf("%d",&testcase);
    scanf("%s",a);

    while(testcase!=0)
    {
       for(i=0;i<81;i++)
       {
    	   if(a[i]=='.')
             a[i]='0'; 
       }
   
       for(i=0;i<81;i++)
        a[i]=a[i]-48;

        col=0;
      //for(i=0;i<81;i++)
       // printf("%d",a[i]);    
       i=0;
       for(row=0;row<9;row++)
        {
        	for(col=0;col<9;col++)
        	{
        		grid[row][col]=a[i];
                        i++;
                }
	}
	    printf("\n");

        if(solvesudoku(grid,0,0)==true)
	    {
		    for(row=0;row<9;row++)
		    {
			    for(col=0;col<9;col++)
			    {
	               printf("%d",grid[row][col]);
			    }
			//printf("\n");
		    }
	    }
        testcase--;
		if(testcase==0)
	    break;
		printf("\n");
		scanf("\n%s",a);	
    }
  
	return 0;
}
