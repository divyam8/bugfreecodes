/*given an array of n numbers give algo for finding no occuring odd no of times
Time complexity:O(n)
Space complexity:O(1)
*/
#include<iostream>
#include<stdlib.h>
 
using namespace std;
int oddnooftimes(int a[],int n)
{
   int i,X=a[0],Y;
   for(i=1;i<n;i++)
   X^=a[i];
  
   return X;
}
int main()
{
  int a[7]={1,2,3,2,3,1,3};
  int n=7;
  int res=oddnooftimes(a,n);  
  cout<<res;
return 0;
}
