#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void resetarr(int arr[3][3])
{
   int n=3;
   int rows[3],cols[3];
    
   memset(rows,1,sizeof rows);
   memset(cols,1,sizeof cols);
  
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<n;j++)
     if(arr[i][j]==0)
     { 
       rows[i]=0;cols[j]=0; 
     }
   }
   for(int i=0;i<n;i++)
   {
     if(rows[i]==0)
     {
       for(int j=0;j<n;j++)
       arr[i][j]=0;     

     }
   }
   for(int i=0;i<n;i++)
   {
     if(cols[i]==0)
     {
       for(int j=0;j<n;j++)
        arr[j][i]=0; 
     }
   }   
   //printing the matrix
   for(int i=0;i<n;i++)
   {
        for(int j=0;j<n;j++)
         cout<<arr[i][j]<<"\t";
     cout<<endl;
   }
}
int main() 
{
  int arr[3][3]={{1,2,3},
                 {4,0,6},
                 {7,8,9}}; 	
  resetarr(arr);
  return 0;
}
