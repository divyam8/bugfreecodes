#include<stdio.h>
#define U 0
#define N 9

bool findunassignedlocation(int grid[N][N], int &row , int &col);
bool issafe(int grid[N][N], int row,int col,int value); 

bool solvesudoku(int grid[N][N])
{
   int row,col,value;

   if(!findunassignedlocation(grid,row,col))// for finding an unassigned location in grid
   return true;
 
   for(value=1;value<=N;value++)  //for finding all the cases from 1 to 9 
   {
   	  if (issafe(grid,row,col,value))
   	  {
   	  	grid[row][col]=value;

   	  	if(solvesudoku(grid)) //recursive call
   	  		return true;

   	  	grid[row][col]=U;
   	  }
   }
   return false;
}

bool findunassignedlocation(int grid[N][N], int &row, int &col)
{
	for(row=0;row<N;row++)
	{
		for(col=0;col<N;col++)
		{
			if(grid[row][col]==U)
				return true;
		}
	}
	return false;
}

bool usedinrow(int grid[N][N],int row, int value)
{
	int col;
	for(col=0;col<N;col++)
	{
			if(grid[row][col]==value)
			return true;
	}
	return false;
}
bool usedincolumn(int grid[N][N],int col,int value)
{
	int row;
	for(row=0;row<N;row++)
	{
		if(grid[row][col]==value)
			return true;
	}
	return false;
}
bool usedinbox(int grid[N][N],int boxstartrow, int boxstartcol,int value)
{
	int row,col;
	for(row=0;row<3;row++)
	{
		for(col=0;col<3;col++)
		{
			if(grid[row+boxstartrow][col+boxstartcol]==value)
				return true;
		}
	}
	return false;
}
bool issafe(int grid[N][N],int row,int col,int value)
{
	return !usedinrow(grid,row,value)&&!usedincolumn(grid,col,value)&&!usedinbox(grid,(row-row%3),(col-col%3),value);
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

        if(solvesudoku(grid)==true)
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
