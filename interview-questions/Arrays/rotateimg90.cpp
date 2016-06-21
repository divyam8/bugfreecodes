#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void rotate90(int image[3][3])
{
   int n=3;
   for(int i=0;i<n;i++)
   {
      for(int j=i+1;j<n;j++)
      swap(image[i][j],image[j][i]);

   }
   for(int i=0;i<n/2;i++)
   for(int j=0;j<n;j++)
   swap(image[i][j],image[n-i-1][j]); 

   //printing the matrix
   for(int i=0;i<n;i++)
   {
        for(int j=0;j<n;j++)
         cout<<image[i][j]<<"\t";
     cout<<endl;
   }
}
int main() 
{
  int image[3][3]={{1,2,3},
                   {4,5,6},
                   {7,8,9}}; 	
  rotate90(image);
  return 0;
}
