/*given an array of n numbers give algo for finding maximum no of repititions
Time complexity:O(n)
Space complexity:O(1)
*/
#include<iostream>
#include<stdlib.h>
 
using namespace std;
void maximumrepetitions(int a[],int n)
{
   int i=0,max=0,maxIndex;
   for(int i=0;i<n;i++)
   a[a[i]%n]+=n;
  
   for(i=0;i<n;i++)
   if(a[i]/n>max)
   {
     max=a[i]/n;
     maxIndex=i;
   }
   cout<<maxIndex;
}
int main()
{
  int a[6]={3,2,1,2,2,3};
  int n=6;
  maximumrepetitions(a,n);  
  
return 0;
}
