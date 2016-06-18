/*given an array of n numbers give algo for finding missing no
Time complexity:O(n)
Space complexity:O(1)
*/
#include<iostream>
#include<stdlib.h>
 
using namespace std;
int findmissingno(int a[],int n)
{
   int i,X=a[0],Y=1;
   for(i=1;i<n;i++)
   X^=a[i];
   for(i=2;i<=n+1;i++)
   Y^=i;
   return X^Y;
}
int main()
{
  int a[7]={1,2,4,6,3,7,8};
  int n=7;
  int res=findmissingno(a,n);  
  cout<<res;
return 0;
}
